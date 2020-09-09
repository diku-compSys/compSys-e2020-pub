#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>

void print_int_arr(int* numbers, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", numbers[i]);
  }
}

void print_float_arr(float* numbers, int n) {
  for (int i = 0; i < n; i++) {
    printf("%f\n", numbers[i]);
  }
}

typedef void (*printer)(void*);

void print_arr(void* arr, int n, int elem_size,
               printer f) {
  char* arr_c = (char*) arr;
  for (int i = 0; i < n; i++) {
    (*f)((void*)(arr_c + i * elem_size));
  }
}

void float_printer(void* p) {
  float* px = (float*) p;
  float x = *px;
  printf("%f\n", x);
}

int cmp_float(const void* px, const void* py) {
  float x = *(float*)px;
  float y = *(float*)py;
  if (x < y) {
    return -1;
  } else if (x > y) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int numbers[10];
  for (int i = 0; i < 10; i++) {
    numbers[i] = rand();
  }

  print_int_arr(numbers, 10);

  float floats[10];
  for (int i = 0; i < 10; i++) {
    floats[i] = rand();
  }

  print_float_arr(floats, 10);

  printf("\nunsorted:\n");
  print_arr(floats, 10, sizeof(float),
            &float_printer);

  printf("\nsorted:\n");
  qsort(floats, 10, sizeof(float),
        cmp_float);
  print_arr(floats, 10, sizeof(float),
            &float_printer);

  printf("&float_printer: %p\n", (void*)&float_printer);
}
