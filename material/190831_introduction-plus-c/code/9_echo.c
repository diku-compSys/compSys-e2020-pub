#include <stdlib.h>
#include <stdio.h>

int main() {
  char input[8];
  printf ("Give me a string\n");
  scanf("%s", input);
  printf ("You wrote: %s\n", input);

  return EXIT_SUCCESS;
}
