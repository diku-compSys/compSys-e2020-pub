#include <stdio.h>

#define square(x) ((x)*(x))

int main() {
  int a = square(3+5);
  int b = a*2;
  int c = b/4;
  printf("%d\n", c);
  return 0;
}

int fadd(int a, int b) {
  return a + b;
}
