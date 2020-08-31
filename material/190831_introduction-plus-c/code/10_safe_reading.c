
#include <stdlib.h>
#include <stdio.h>

int main() {
  char input[20];
  printf ("Give me a string\n");
  fgets(input, sizeof(input), stdin);
  printf ("You wrote: %s\n", input);

  return EXIT_SUCCESS;
}
