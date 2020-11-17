#include "csapp.h"
#include <unistd.h>
#include <assert.h>

#define BUFSIZE 4096

int main(int argc, char** argv) {
    int n;
    char buf[BUFSIZE];

    assert(argc == 3);
    int from = Open(argv[1], O_RDONLY, 0);
    int to = Open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    while((n = Rio_readn(from, buf, BUFSIZE)) != 0)
      Rio_writen(to, buf, n);

    close(from);
    close(to);
}
