#include "csapp.h"

int main(int argc, char **argv) {
  int n;
  rio_t rio;
  char buf[MAXLINE];


  /*
   * the exercise explicitly states to solve the problem without changing
   * the while loop in the bottom of main().
   *
   * to achieve this, I use dup2() to copy the file table entry from the
   * file descriptor of the opened file to descriptor 0 (stdin), meaning
   * bytes read from "stdin" will actually come from the file :):)
   *
   */

  /* changes start here */
  if (argc == 2) {

    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
      fprintf(stderr, "fopen() error: %s\n", strerror(errno));
      exit(1);
    }

    int fd = fileno(file);            // according to the man page, fileno never fails :PP
    if (dup2(fd, STDIN_FILENO) < 0) { // dup2 returns the dupped fd on success, -1 on error
      fprintf(stderr, "dup2() error: %s\n", strerror(errno));
      exit(1);
    }
  }
  /* changes end here */


  Rio_readinitb(&rio, STDIN_FILENO);

  while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
    Rio_writen(STDOUT_FILENO, buf, n);
  }
}
