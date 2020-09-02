#include <stdlib.h>
#include <stdio.h>

int main() {
  int a = 1;
  int b = 2 + a;
  a += b; // a = a + b
  a *= 2;
  a++; // a = a + 1
  a--;
  ++a; // a = a + 1
  printf("a is %d and b is %d\n", a, b);

  return EXIT_SUCCESS;
}
