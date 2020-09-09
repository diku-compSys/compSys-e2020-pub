#include <stdio.h>
#include <string.h>

int tester(int* c, int k);
int update(int* c, int k, int v);

int main() {
  int i, k;
  int x[1000];

  for(i = 0; i < 1000; ++i){
    update(x, i, i);
  }

  printf("Enter integer in 0..9999: ");
  scanf("%d", &k);

  tester(x, k);
}

int tester(int* c, int k) {
  printf("x[%d] = %d\n", k, c[k]);
  return 1;
}

// Update of array c in index i with v
int update(int* c, int k, int v) {
  int val = v*v;
  // By accidence, I swap the index and the value
  // c[val] = k;
  c[k] = val;
  return 1;
}