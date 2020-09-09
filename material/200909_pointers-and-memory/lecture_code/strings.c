#include <stdio.h>
#include <strings.h>

int stringlength(char* s) {
  int count = 0;
  while (s[count] != 0) {
    count++;
  }
  return count;
}

int main(int argc, char** argv) {
  int sum = 0;
  for (int i = 1; i < argc; i++) {
    sum += stringlength(argv[i]);
  }

  char res[sum+1];
  res[sum] = '\0';
  int x = 0;

  for (int i = 1; i < argc; i++) {
    int n = stringlength(argv[i]);
    for (int j = 0; j < n; j++) {
      res[x] = argv[i][j];
      x++;
    }
  }

  printf("%s\n", res);
}
