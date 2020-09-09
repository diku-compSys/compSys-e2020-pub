#include <stdio.h>
#include <string.h>


int main() {
  char* c = "test";

  while (*c != 0) {
    printf("%s\n", c);
    c++;
  }


  int y = 0;
  int x = 2;
  int *yptr = &y;
  int *xptr = &x;
  *xptr += 5;
  printf("x = %i\n", x);
  y = 5 + (*xptr);

  printf("y = %i\n", y);
  printf("xptr = %p\n", (void *) xptr);
  printf("yadder = %p\n", (void *) &y);


  printf("yptr   = %p\n", (void *) yptr);
  yptr--;
  *yptr -=3;
  printf("yptr++ = %p\n", (void *) yptr);

  printf("x = %i\n", x);

  int *cptr = (int *) &c;
  printf("c1 %i\n", *cptr);


}
