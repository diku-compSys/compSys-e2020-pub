
#include <stdlib.h>
#include <stdio.h>

#define BAD_INPUT 0

int main(int argc, char *argv[]) {
  int input;
  int input2;
  int result;

  if(argc == 2) { // 1st argument is the name of the program
    int res;
    res = sscanf(argv[1],"%d and %d",&input, &input2);
    if (res == BAD_INPUT) {
      printf("Bad value\n");
    }
    else {
      printf("Input: %d\n", input);
      result = input + input2;
      printf("Result: %d \n", result);
    }
  }
  else {
    printf("Not one argument\n");
  }

  return EXIT_SUCCESS;
}



