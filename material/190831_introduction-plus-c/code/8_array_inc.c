#include <stdlib.h>
#include <stdio.h>

int main() {
  int a[16];
  int b = 2;
  a[0] = 1;
  for (int i = 1; i <= 18; i++) {
    a[i] = a[i-1] + 1;
  }
  printf("final = %d\n", a[15]);
  printf("final b = %d\n", b);

  return EXIT_SUCCESS;
}
