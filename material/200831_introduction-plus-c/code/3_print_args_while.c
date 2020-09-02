#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  int i = 1;
  while (i < argc) {
    printf("Argument number %d: %s\n", i, argv[i]);
    i = i + 1;
  }
  // Implicit return EXIT_SUCCESS; -- But it is better to keep
}
