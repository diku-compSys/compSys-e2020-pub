#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc == 2) { // 1 argument
    return EXIT_SUCCESS;
  }
  else if (argc == 4) { // 3 arguments
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  }
}