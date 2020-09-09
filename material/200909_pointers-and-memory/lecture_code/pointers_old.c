#include <stdio.h>
#include <string.h>

void recurse(int i) {
  int x;
  printf("&x: %p\n", (void*)&x);
  if (i > 0) {
    recurse(i-1);
  }
}

void fun_arr(char bytes[]) {
  printf("sizeof(bytes) = %d\n", (int)sizeof(bytes));
}

int main() {
  int x = 22;
  int* px = &x;

  printf("x: %d\n", x);
  printf("px: %p\n", (void*)px);
  printf("*px: %d\n", *px);

  recurse(10);

  char bytes[sizeof(int)];
  memcpy(bytes, &x, sizeof(int));

  for (unsigned int i = 0; i < sizeof(int); i++) {
    printf("%d\n", bytes[i]);
  }

  printf("sizeof(bytes) = %d\n", (int)sizeof(bytes));
  fun_arr(bytes);

  printf("&bytes = %p\n", (void*)&bytes);
  printf("&bytes[0] = %p\n", (void*)&bytes[0]);
  printf("&bytes[1] = %p\n", (void*)&bytes[1]);
}
