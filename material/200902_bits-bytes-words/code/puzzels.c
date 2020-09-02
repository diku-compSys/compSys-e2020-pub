#include <stdio.h>
#include <stdlib.h>

int main () {

    int x = 0; //foo();
    int y = 0; //bar();
    unsigned ux = x;
    unsigned uy = y;

    int result;

    // False, as we can get underflow for signet numbers
    x = -2000000000;
    x *=2;
    result = x < 0;
    printf("x < 0 => ((x*2) < 0)       : x=%i => %i\n", x, result);

    // Correct! The representation of a unsigned number will always be larger than or equal to 0
    x = 0;
    ux = x;
    printf("ux >= 0                    : x=%i => ux=%u, thus %i\n", x, ux, ux >= 0);

    // Correct! x & 7 == 7 implies that the three least significant bits of x are true.
    // Left-shifting these 30 bit result in the most significant to be true.
    // x is a signed value, and having the most significant to be true implies that the value is negative.
    x = 7;
    printf("x & 7 == 7 => (x<<30) < 0  : x=%i => %i\n", x, (x<<30) < 0);

    // False! -1 is defined by the number 0xFFFFFFFF, which is the highest unsigned number. Nothing can be larger than this.
    x = 0;
    ux = x;
    printf("ux > -1                    : x=%i => ux=%u, thus %i\n", x, ux, ux > -1);

    // False. The negation of the most negative number is equal to it self.
    x = 3;
    y = -2147483648; // INT_min
    x = -x;
    y = -y;
    printf("x > y => -x < -y           : x=%i, -y=%i => %i\n", x, y, x < y);

    // False, as we can get overflow.
    x = 200000000;
    x *=x;
    printf("x * x >= 0                 : x=%i => %i\n", x, x >= 0);

    // False, as we can get overflow.
    x = 0;
    y = 0;
    printf("x > 0 && y > 0 => x + y > 0: x=%i, y=%i => %i\n", x, y, x + y > 0);

    // Correct! All positive values have a representation as a negative value.
    x = 0;
    printf("x >= 0 => -x <= 0          : x=%i => %i\n", x, -x <= 0);

    // False! The most negative number does not have a representation as a positive number.
    // We have more negative numbers than positive numbers.
    x = -2147483648; // INT_min
    x = -x;
    printf("x <= 0 => -x >= 0          : -x=%i => %i\n", x, x >= 0);

    // False! If x is 0, the negative value is also 0. 0|0 is 0 an right-shifted 31 places will still be 0.
    // I think I made the wrong argument at the lecture.
    x = 0;
    printf("(x|-x)>>31 == -1           : x=%i => %i\n", x, (x|-x)>>31 == -1);

    // True. Shifting n places to right is equal to dividing with 2^n for positive numbers.
    x = 0;
    ux = x;
    printf("ux >> 3 == ux/8            : x=%i => ux=%u, thus %i\n", x, ux, ux >> 3 == ux/8);

    // False! Division for negative numbers rounds down (i.e. -9/8 = -2). Shifting to the right is equal to division with rounding toward zero. (i.e. -9 >> 3 = -1)
    x = -9;
    printf("x >> 3 == x/8              : x=%i => %i\n", x, x >> 3 == x/8);

    // False. 0 bit-wise with anything is equal to 0. It hold for all other values.
    x = 0;
    printf("x & (x-1) != 0             : x=%i => %i\n", x, x & (x-1) != 0);

    return EXIT_SUCCESS;
}