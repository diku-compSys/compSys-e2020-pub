#include <stdlib.h>
#include "ternary.h"

#define ARGNUM 1

int main(int argc, char**argv) {
    if (argc != ARGNUM + 1) {
        printf("Usage:");
        printf("  %s [filename]\n", (argv[0]+2));
        printf("    Filename: a file containing a stream of line separated hex-addresses");
        return(0);
    }

    //TODO: Make some test
    
    return 0;
}
