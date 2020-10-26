// Demonstrates sharing memory between parent and child.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <assert.h>

int main(int argc, char** argv) {
  char *filename = argv[1];
  int num_bytes = 10000;

  FILE* file = fopen(filename, "r");
  assert(file != NULL);
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  unsigned char *data = mmap(NULL,
                             size,
                             PROT_WRITE | PROT_READ,
                             MAP_ANON | MAP_SHARED,
                             0, 0);
  assert(data != MAP_FAILED);

  pid_t pid = fork();
  if (pid == 0) {
    assert(fread(data, 1, size, file) == size);
    exit(0);
  } else {
    fclose(file);
    waitpid(pid, NULL, 0);
    for (int i = 0; i < size; i++) {
      putchar(data[i]);
    }
  }
}
