#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int num_gib = atoi(argv[1]);
  size_t to_alloc = num_gib * 1024 * 1024 * 1024;

  unsigned char *p = malloc(to_alloc);

  if (p) {
    while (1) ;
  }
}
