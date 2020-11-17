#include "csapp.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
  struct stat stat;
  char *type, *readok;

  /* changes start here */
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file descriptor>\n", argv[0]);
    exit(0);
  }

  char *endptr;
  int fd = (int) strtol(argv[1], &endptr, 10);

  if (endptr != NULL || endptr == argv[1]) { // if conversion of command line arg failed
    fprintf(stderr, "strtol() error: %s\n", strerror(errno));
    exit(1);
  }

  if (fstat(fd, &stat) != 0) {
    fprintf(stderr, "fstat() error: %s\n", strerror(errno));
    exit(1);
  }
  /* changes end here */ 


  if (S_ISREG(stat.st_mode))    /* Determine file type */
    type = "regular";
  else if (S_ISDIR(stat.st_mode))
    type = "directory";
  else
    type = "other";


  if ((stat.st_mode & S_IRUSR)) /* Check read access */
    readok = "yes";
  else
    readok = "no";

  printf("type: %s, read-enable: %s\n", type, readok);
  exit(0);
}
