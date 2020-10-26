#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  size_t num_gib = atoi(argv[1]);
  int num_writes = atoi(argv[2]);
  int stride = atoi(argv[3]);
  size_t to_alloc = num_gib * 1024 * 1024 * 1024;

  printf("allocating %ld bytes\n", (long)to_alloc);

  unsigned char *p = malloc(to_alloc);

  if (p) {
    while (1) {
      for (int i = 0; i < num_writes; i++) {
        p[(i*stride) % to_alloc] = rand();
      }
    }
  }
}
