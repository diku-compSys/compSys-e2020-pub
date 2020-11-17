#include "csapp.h"
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv)
{
    char c;
    struct stat stat;

    assert(argc == 3);
    int from = Open(argv[1], O_RDONLY, 0);
    int to = Open(argv[2], O_RDWR | O_CREAT, 0666);

    Stat(argv[1], &stat);
    size_t from_size = stat.st_size;

    void *from_p = Mmap(NULL, from_size, PROT_READ,
                        MAP_FILE | MAP_PRIVATE | MAP_NOCACHE,
                        from, 0);

    assert(ftruncate(to, from_size) == 0);

    void *to_p = Mmap(NULL, from_size, MAP_FILE | PROT_WRITE, MAP_SHARED, to, 0);

    memcpy(to_p, from_p, from_size);
    Munmap(to_p, from_size);
    close(from);
    close(to);
}
