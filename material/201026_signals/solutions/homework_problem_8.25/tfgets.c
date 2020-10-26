#include <stdio.h>
#include <signal.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define MAX_LINE_LEN  128
#define EXIT_TIMEOUT  42
#define TIMEOUT_SECS  5


char *tfgets(char buffer[], int max_line_len, FILE *stream);
void on_timeout(int sig);

int main() {
  char buffer[MAX_LINE_LEN];
  char *user_input = tfgets(buffer, MAX_LINE_LEN, stdin);

  if (user_input == NULL) {
    printf("(from main) user too slow !!! >:(\n");
  }
  else {
    printf("(from main) user input: %s", user_input);
    free(user_input);
  }
  exit(0);
}


char *tfgets(char *buffer, int max_line_len, FILE *stream) {

                                                          
  char *shared_mem = mmap(NULL, max_line_len,                   // setup shared memory:
                          PROT_READ | PROT_WRITE,               // - make it read and write-enable.
                          MAP_SHARED | MAP_ANONYMOUS,           // - make it shared between this process and its children.
                          -1, 0);                               // - don't worry about these parameters :D
  pid_t pid;
  assert((pid = fork()) >= 0);

  /*
   *  CHILD
   */
  if (pid == 0) {
    assert(signal(SIGALRM, on_timeout) != SIG_ERR);             // setup SIGALRM handler

    alarm(TIMEOUT_SECS);                                        // send a SIGALRM to this process in 5 seconds

    char input[max_line_len];
    assert(fgets(input, max_line_len, stream) != NULL);         // get user input and copy to shared mem
    memcpy(shared_mem, input, max_line_len);
    exit(EXIT_SUCCESS);
  }


  /*
   *  PARENT
   */
  else {

    int   status;
    if (waitpid(pid, &status, 0) > 0) {                         // wait until child exits normally after
                                                                // fetching user input or dies from SIGALRM.
      if (WIFEXITED(status)) {

        int exit_code = WEXITSTATUS(status);
        if (exit_code == EXIT_SUCCESS) {                        // if child exited with exit code 0, extract
                                                                // user input from mmapped shared memory.
          char *input_out = malloc(max_line_len);

          memcpy(input_out, shared_mem, max_line_len);          // copy shared_mem to input_out.

          assert(munmap(shared_mem, max_line_len) == 0);        // unmap shared memory now that we have fetched the user input.

          return input_out;
        }

        else if (exit_code == EXIT_TIMEOUT) {
          printf("Child %d timed out\n", pid);
        }
      }

      else if (WIFSIGNALED(status)) {                           // if child terminated by signal
        int sig_num = WTERMSIG(status);
        char msg[42];
        sprintf(msg, "Child terminated by signal %d", sig_num);
        psignal(sig_num, msg);

      } else { // catch-all
        printf("Child %d exited abnormally for reasons unknown\n", pid);
      }
    }

    assert(munmap(shared_mem, max_line_len) == 0);
    return NULL;
  }
}

void on_timeout(int sig) {
  exit(EXIT_TIMEOUT);
}
