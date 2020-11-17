#include "csapp.h"
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv)
{
    char c;

    assert(argc == 3);
    int from = Open(argv[1], O_RDONLY, 0);
    int to = Open(argv[2], O_WRONLY | O_CREAT, 0666);

    while(Read(from, &c, 1) != 0)
      Write(to, &c, 1);

    close(from);
    close(to);
}
