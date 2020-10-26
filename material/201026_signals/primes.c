#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>

// Some large primes:
//
// 982451653
// 2147483647

int file_pipe(FILE* files[2]) {
  int fds[2];

  int r = pipe(fds);

  if (r == 0) {
    files[0] = fdopen(fds[0], "r");
    files[1] = fdopen(fds[1], "w");

    if (files[0] && files[1]) {
      return 0;
    } else {
      return 1;
    }
  } else {
    return r;
  }
}

int divisor_in(int x, int from, int to) {
  for (int d = from; d < to; d++) {
    if (x % d == 0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: %s <nprocs> <number>\n", argv[0]);
    return 1;
  }

  int nprocs = atoi(argv[1]);
  int x = atoi(argv[2]);
  int chunk_size = (x-2) / nprocs;

  FILE* child_pipes[nprocs];
  pid_t children[nprocs];

  for (int i = 0; i < nprocs; i++) {
    FILE* files[2];
    assert(file_pipe(files) == 0);
    pid_t pid = fork();
    assert(pid >= 0);
    if (pid == 0) {
      // We are child.
      fclose(files[0]);

      int divisible = divisor_in(x, 2 + chunk_size * i, 2 + chunk_size * (i+1));
      assert(fwrite(&divisible, sizeof(int), 1, files[1]) == 1);
      fclose(files[1]);
      exit(0);
    } else {
      // We are parent.
      fclose(files[1]);

      children[i] = pid;
      child_pipes[i] = files[0];
    }
  }

  int prime = 1;
  for (int i = 0; i < nprocs; i++) {
    int divisible;
    assert(fread(&divisible, sizeof(int), 1, child_pipes[i]) == 1);
    if (divisible) {
      prime = 0;
    }
    waitpid(children[i], NULL, 0);
  }

  if (prime) {
    printf("%d is prime.\n", x);
  } else {
    printf("%d is not prime.\n", x);
  }
}
