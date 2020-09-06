# Exercises for 7/9-2020

Author: Oleks Shturmov <oleks@oleks.info> and Michael Kirkedal Thomsen <kirkedal@acm.org>

These exercises will give you some practice in working with bit representation. We will also practice simple integer arithmetic

---

For all of the below, you should use `make` to build your programs. To
parametrize `make` to build with all the necessary compiler flags, start by
writing down a `Makefile` containing the following:

```
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
```

Now, to compile the programs below, just `make` them. For example:

```
$ make unary
```

---

# Boolean arithmetic

Show, using truth tables, that the following holds;

  * `~(A & B)` = `~A | ~B`  -- (De Morgan's Law),
  * `(A ^ B) & A` = `A & ~B`,
  * `(A & B) | (C & (A ^ B))` = `C ^ ((A ^ C) & (B ^ C))`

De Morgan's Law is a very important equation for de sign of logic circuits.

The last equation is two different ways of calculating the carry-out bit of a binary adder. Recap what the carry-out is and it is used for. Also how do we calculate the sum bit?

---

## `./hexabyte path`

Write a C program `hexabyte` that handles command-line arguments as above. When
given a path argument, it opens the file and prints it byte-by-byte, using the
format `"%02x\n"` for each byte. (Hint: Use `fread` and `feof`.)

Sample interaction with `hexabyte`:

```
$ ./hexabyte Makefile
43
43
3d
67
...
20
2d
67
0a
```

## `./bitflip value index`
Make a program in C that takes a `value` (parsed from an integral 64-bit value) and an `index` (integral between 0 and 63) and negates the `index`'th bit in the binary representation of `value`. The function should print the updated `value` and return `EXIT_SUCCESS`.

If the number of arguments is different from two indicate this by printing appropriate text to the user and return `EXIT_FAILURE`. If either `value` or `index` does not parse as an integral value indicate this by printing and return `EXIT_FAILURE`. It `index` is out of bounds indicate this by printing and return `EXIT_SUCCESS`.

## Play with integer number representations

At [Integral Number Representations](http://topps.diku.dk/compsys/integers.html)
you find a small game you can play by converting from different integer number
representations.

Get 10 correct answers..

Next, answer all of the following:

* http://topps.diku.dk/compsys/integers.html#NjdfZmFsc2VfMV8yXzE=
* http://topps.diku.dk/compsys/integers.html#NjFfZmFsc2VfMV8yXzE=
* http://topps.diku.dk/compsys/integers.html#MTAzX2ZhbHNlXzFfMl8x
* http://topps.diku.dk/compsys/integers.html#OTBfZmFsc2VfMV8yXzE=
* http://topps.diku.dk/compsys/integers.html#MjU1X2ZhbHNlXzFfMF8y
* http://topps.diku.dk/compsys/integers.html#MTUzX2ZhbHNlXzFfMF8y
* http://topps.diku.dk/compsys/integers.html#MjE5X2ZhbHNlXzFfMF8x
* http://topps.diku.dk/compsys/integers.html#OTBfZmFsc2VfMV8wXzE=

## Play integer representation and arithmetic
Here it is! The sequel to the [Integer representation game](http://topps.diku.dk/compsys/integers.html)

Make a winning streak at the [integer arithmetic game](http://topps.diku.dk/compsys/integer-arithmetic.html). Then push your skills to the limit by winning the [floating point game](http://topps.diku.dk/compsys/floating-point.html).

The critics are saying:
* [Game Informer](http://www.gameinformer.com/): "Have taken the world with storm! Who would have thought arithmetic was so much fun."
* [dupreeh, Astralis](https://www.astralis.gg/team/dupreeh): "Much better than CS:go! Now I will start at DIKU to become a professional."
* [PC Gamer](http://www.pcgamer.com/): "This FP game must be the hardest game ever made. Nothing makes sense for me."

## `./badd a b`
Recap you binary number arithmetic. Write a C program that given two 64-bit integral values, `a` and `b`, calculates the sum of `a` and `b` using the method of a binary ripple-carry adder. (See textbook.)
You program should print the sum and a possible overflow bit and return `EXIT_SUCCESS`.

If the number of arguments is different from two indicate this by printing appropriate text to the user and return `EXIT_FAILURE`. If either `value` or `index` does not parse as an integral value indicate this by printing and return `EXIT_FAILURE`.

## `./hexdump path` (Medium to hard)

The `hexabyte` utility above is a miniature variant of the standard
`hexdump(1)` utility, which we hope you will grow to know and love throughout
this course.

The utility uses a slightly more evolved output format. We will learn more
about the option-less format next week. This week we show only the "canonical"
format achieved with `hexdump -C`:

```
$ hexdump -C Makefile 
00000000  43 43 3d 67 63 63 0a 43  46 4c 41 47 53 3d 2d 73  |CC=gcc.CFLAGS=-s|
00000010  74 64 3d 63 31 31 20 2d  57 61 6c 6c 20 2d 57 65  |td=c11 -Wall -We|
00000020  72 72 6f 72 20 2d 57 65  78 74 72 61 20 2d 70 65  |rror -Wextra -pe|
00000030  64 61 6e 74 69 63 20 2d  67 0a                    |dantic -g.|
0000003a
```

A canonical hexdump shows 16 bytes per line, each byte printed as a 2-digit hex
number, padded with 0's.

Each line starts with the offset of the first byte printed on that line, from
the start of the file. The offset is printed as an 8-digit hex number, padded
with 0's. The very last line prints the size of the file, in the same format.
(What is the size of `Makefile` in decimal notation? In decimal notation, how
big a file can `hexdump -C` handle?)

Each line of bytes is followed by a character printout of the 16 bytes,
enclosed in pipe-characters.

There are two spaces between the offset and the first byte, between the 8th and
9th byte, and between the last byte and the character printout.

The next-to-last line may have fewer than 16 bytes, as not all files are
aligned to divide evenly by 16. The character printout in this case is padded
to vertically align with the character output above.

Write a C program `hexdump` to mimic the behaviour of `hexdump -C`.


## Conversion to ternary-coded representation and arithmetic (Expert -- taken from exam 2017)
*(Note, from take-home-exam. You will not see such large C implementation questions at the exam.)*

Logic does not have to be based on binary numbers. For a period (mainly in Russia) logic gates based on three-value logic (also called ternary logic) was widely researched. Here we will therefore implement a simple library in C for ternary logic number conversion.

We will simulate ternary logic by encoding each ternary value with 2 bits, thus using only the 2-bit values `00`, `01`, and `10` to encode 0, 1, and 2 respectively.
For example, the decimal number 16 is in encoded as `011001` using our simulated ternary format (16 = 3^2 * 1 + 3^1 * 2 + 3^0 * 1$).
Note that our ternary logic numbers have a less compact representation than binary represented numbers as the $2$-bit value $11$ is undefined. Consider the consequences of this and how you are handling this in your implementation.

Use the file `ternary.h` as the basis for your implementation and make the implementation in `ternary.c`; all located in the [ternary subdirectory](ternary/). There is also a Makefile that you are welcome to use. Note in `ternary.h` that a ternary logic number is represented using a `unsigned long` wrapped in a `struct`.

### Conversion to ternary
Implement a function `toTernary` that given a binary number of type `unsigned long` returns the value using ternary logic number representation.

### Conversion from ternary
Implement a function `fromTernary` that given a number of ternary logic representation returns the value as a `unsigned long`.

### Ternary addition
Implement a function `addTernary` that given two ternary logic numbers returns the sum of the two inputs. Overflow in `addTernary` must behave like overflow in GCC compiled C integer addition for `unsigned long` with the exception of the overflow range.

The addition must be done directly on the ternary logic number representation and, hence, _not_ through conversion to binary representation and back. Hint: base your solution on the ripple-carry adder principle.

