#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  for (int i = 1; i < argc; i++) {
    printf("Argument number %d: %s\n", i, argv[i]);
  }
  return EXIT_SUCCESS;
}

