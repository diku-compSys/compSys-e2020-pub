// This program demonstrates how to communicate between one process
// and another, with all the details.  It is supposed to illustrate
// the essential details you will need in A4.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

// The pipe() system call produces a single pipe, as well as "file
// descriptors" representing the read end and the write end.  Working
// directly with file descriptors is awkward, so this wrapper function
// uses fdopen() to produce FILE* objects corresponding to the read
// end and write end of the pipe.
//
// After a call
//
//    file_pipe(files);
//
// anything you write on files[1] can be read from files[0].  Since
// the read/write blocks, this should be done by different processes.
//
// Returns zero on success.
static int file_pipe(FILE* files[2]) {
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

// To illustrate file_pipe(), we will write a simple program that
// writes an array of integers from a producer (the parent) to a
// consumer (the child).
int main() {
  FILE* files[2];
  assert(file_pipe(files) == 0);

  FILE* read_end = files[0];
  FILE* write_end = files[1];

  pid_t pid;
  if ((pid = fork()) == 0) {
    // In child.  Since we will only ever *read* from the pipe in the
    // child, we close our copy of the write-end.  This is *critical*,
    // because otherwise feof() below will never return true, as a
    // pipe does not reach end-of-file until *all* write-ends have
    // been closed - including the one we inherited due to the fork()!
    // Try removing the next line and see what happens.
    fclose(write_end);

    // Then we read from the read-end until it reaches end-of-file.
    while (!feof(read_end)) {
      int x;
      if (fread(&x, sizeof(int), 1, read_end) == 1) {
        printf("%d\n", x);
      }
    }

  } else {
     // In parent.  We close the read-end, although it's not as
     // critical as closing the write-end in the child.
    fclose(read_end);

    int n = 10; // The number of values to write
    for (int i = 0; i < n; i++) {
      int x = rand() % 100;
      assert(fwrite(&x, sizeof(int), 1, write_end) == 1);
    }

    // Close the write-end to indicate that there will be no more data
    // coming on the pipe.  Otherwise, the child would never die, and
    // the waitpid() call would block infinitely.
    fclose(write_end);

    int status;
    waitpid(pid, &status, 0);
  }
}
