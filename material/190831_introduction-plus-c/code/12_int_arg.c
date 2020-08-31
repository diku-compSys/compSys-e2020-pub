
#include <stdlib.h>
#include <stdio.h>

#define BAD_INPUT 0

int main(int argc, char *argv[]) {
  int input;

  if(argc == 2) { // 1st argument is the name of the program
    int res;
    res = sscanf(argv[1],"%d", &input);
    if (res == BAD_INPUT) {
      printf("Bad value\n");
    }
    else {
      printf("Input was: %d\n", input);
    }
  }
  else {
    printf("Not one argument\n");
  }

  return EXIT_SUCCESS;
}
