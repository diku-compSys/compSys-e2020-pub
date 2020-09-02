#include <stdio.h>
#include <stdlib.h>

int main () {

    int x = 0; //foo();
    int y = 0; //bar();
    unsigned ux = x;
    unsigned uy = y;

    int result;

    // x = 0;
    // printf("x < 0 => ((x*2) < 0)       : x=%i => %i\n", x, (x*2) < 0);

    // x = 0;
    // ux = x;
    // printf("ux >= 0                    : x=%i => ux=%u, thus %i\n", x, ux, ux >= 0);

    // x = 0;
    // printf("x & 7 == 7 => (x<<30) < 0  : x=%i => %i\n", x, (x<<30) < 0);

    // x = 0;
    // ux = x;
    // printf("ux > -1                    : x=%i => ux=%u, thus %i\n", x, ux, ux > -1);

    // x = 0;
    // y = 0;
    // printf("x > y => -x < -y           : x=%i, y=%i => %i\n", x, y, -x < -y);

    // x = 0;
    // printf("x * x >= 0                 : x=%i => %i\n", x, x * x >= 0);

    // x = 0;
    // y = 0;
    // printf("x > 0 && y > 0 => x + y > 0: x=%i, y=%i => %i\n", x, y, x + y > 0);

    // x = 0;
    // printf("x >= 0 => -x <= 0          : x=%i => %i\n", x, -x <= 0);

    // x = 0;
    // printf("x <= 0 => -x >= 0          : x=%i => %i\n", x, -x >= 0);

    // x = 0;
    // printf("(x|-x)>>31 == -1           : x=%i => %i\n", x, (x|-x)>>31 == -1);

    // x = 0;
    // ux = x;
    // printf("ux >> 3 == ux/8            : x=%i => ux=%u, thus %i\n", x, ux, ux >> 3 == ux/8);

    // x = 0;
    // printf("x >> 3 == x/8              : x=%i => %i\n", x, x >> 3 == x/8);

    // x = 0;
    // printf("x & (x-1) != 0             : x=%i => %i\n", x, x & (x-1) != 0);

    return EXIT_SUCCESS;
}