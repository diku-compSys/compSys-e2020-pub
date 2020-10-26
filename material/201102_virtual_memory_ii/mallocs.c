#include <stdio.h>
#include <stdlib.h>

int main() {
  for (int i = 1; i < 30; i++) {
    int num_bytes = 1 << i;
    printf("malloc(%d)\n", num_bytes);
    malloc(num_bytes);
  }
}
