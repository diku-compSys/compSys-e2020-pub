#include "csapp.h"
#include <unistd.h>
#include <assert.h>

#define BUFSIZE 4096

int main(int argc, char** argv)
{
    int n;
    rio_t rio;
    char c;

    assert(argc == 3);
    int from = Open(argv[1], O_RDONLY, 0);
    int to = Open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    Rio_readinitb(&rio, from);
    while((n = Rio_readnb(&rio, &c, 1)) != 0)
      Rio_writen(to, &c, 1);

    close(from);
    close(to);
}
