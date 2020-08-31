#include <stdlib.h>
#include <stdio.h>

int main() {
  int a = 3;
  int b = 5;
  int c = -2;
  a += (c = a++ - (b += --c) + ++b);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);

  return EXIT_SUCCESS;
}