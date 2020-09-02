#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc == 2) { // 1 argument
  	printf("One arguments: %s\n", argv[0]);
    return EXIT_SUCCESS;
  }
  else if (argc == 4) { // 3 arguments
  	printf("Three arguments: %s\n", argv[0]);
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  }
}