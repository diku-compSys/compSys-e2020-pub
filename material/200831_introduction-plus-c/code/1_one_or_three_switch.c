#include <stdlib.h>

int main(int argc, char* argv[]) {
  (void) argv; // Don't do this at home
  switch (argc) {
    case 2:
      return EXIT_SUCCESS;
      break;
    case 4:
      return EXIT_SUCCESS;
      break;
    default:
      return EXIT_FAILURE;
      break;
  }
}