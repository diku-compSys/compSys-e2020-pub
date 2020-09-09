
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  if (argc != 2) { // 1 argument
    printf("Usage %s filename\n", argv[0]);
    return EXIT_SUCCESS;
  }

  FILE* fp;
  fp = fopen(argv[1], "r");

  if (errno == 0) {
    printf("File: %s was found, status: %d\n", argv[1], errno);

    char last;
    char cur;
    cur = fgetc(fp);
    while (!feof(fp)) {
      last = cur;
      cur = fgetc(fp);
    }
    printf("The last char was: %c\n", last);

    fclose(fp);
  }
  else {
    printf("Reading %s resulted in error %d\n", argv[1], errno);
  }

  return EXIT_SUCCESS;
}