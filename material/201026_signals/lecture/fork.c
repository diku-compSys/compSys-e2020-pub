#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

int main() {
  pid_t pid;

  int parent_fds[2];
  assert(pipe(parent_fds) == 0);

  int child_fds[2];
  assert(pipe(child_fds) == 0);

  FILE *parent_read_f = fdopen(parent_fds[0], "r");
  FILE *parent_write_f = fdopen(parent_fds[1], "w");

  FILE *child_read_f = fdopen(child_fds[0], "r");
  FILE *child_write_f = fdopen(child_fds[1], "w");

  if ((pid = fork()) == 0) {
    // In child
    int x;
    assert(fread(&x, sizeof(int), 1, parent_read_f) == 1);
    x = x * 2;
    assert(fwrite(&x, sizeof(int), 1, child_write_f) == 1);
  } else {
    // In parent
    int x = 2;
    assert(fwrite(&x, sizeof(int), 1, parent_write_f) == 1);
    assert(fread(&x, sizeof(int), 1, child_read_f) == 1);
    printf("Parent received: %d\n", x);
  }
}
