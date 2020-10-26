#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#define NUM_CHILDREN 2

void child_lifespan();
int make_illegal_write();

int main() {
  int status, i;
  pid_t pid;

  for (i = 0; i < NUM_CHILDREN; i++) {
    if ((pid = fork()) == 0) {
      child_lifespan();
    }
    sleep(1);
  }

  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFSIGNALED(status)) {
      int sig_num = WTERMSIG(status);     // fetch number of the terminating signal
      char msg[42];
      sprintf(msg, "child %d terminated by signal %d", pid, sig_num);
      psignal(sig_num, msg);
    }

    else if (WIFEXITED(status)) {
      printf("child %d terminated normally with exit status = %d\n",
          pid, WEXITSTATUS(status));
    }
    else {
      printf("child %d terminated abnormally ://\n", pid);
    }
  }

  /* The only normal termination is if there are no more children */
  if (errno != ECHILD) {
    fprintf(stderr, "waitpid() error\n");
    exit(1);
  }

  exit(0);
}


/*
 *  during its lifespan of 20 seconds, a child process will do the following 10 times:
 *  - sleep for 2 seconds.
 *  - wake up and, with probability 1/8,
 *    attempt to write to read-only segment.
 * 
 *  if child survives for 20 seconds without any
 *  illegal activity; terminates with exit code 0.
 */
void child_lifespan() {
  srand(time(NULL));

  int my_pid = getpid();

  printf("child %d spawned: going to sleep for 2 seconds ...\n", my_pid);
  for (int i = 10; i >= 0; i--) {

    sleep(2);

    if (rand() % 8 == 0)   // with probability 1/8, make an illegal write !!
      make_illegal_write();

    printf("child %d: nothing illegal going on here !! going back to sleep for 2 secs ...\n", my_pid);
  }

  exit(0);
}

int make_illegal_write() {
  char *address_probably_in_read_only_segment = (char*) 0x7;
  *address_probably_in_read_only_segment = ' ';
  return 0;
}

