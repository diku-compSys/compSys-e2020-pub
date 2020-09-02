# Exercises for 2020-08-31

These exercises are intended to give your a first quick feeling of C
and prepare you for what comes in A0. Use the exercise classes to get
help.  This is not part of the assignment.

For all of the below, you should use `make` to build your programs. To
parametrize `make` to build with all the necessary compiler flags, start by
writing down a `Makefile` containing the following:

```
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
```

Then when you add a program `foo`, add a rule to `Makefile` as
follows:

```
foo: foo.c
	$(CC) -o foo foo.c $(CFLAGS)
```

**Beware**: the leading whitespace *must* be a single tab character.
Now, to compile `foo`, just run `make foo`. For example:

```
$ make mynameis
```

There are ways to automate parts of this, but we recommend being
explicit until you get a firm grasp on what `make` does.

In the following, we colloquially use "print" as slang for writing to
standard output.

## Printing in C

Write a C program `mynameis` that prints your name.

## Input arguments in C

Write a C program `repeatme` that given a string as argument, prints
the string twice on separate lines.

If the program gets a number of arguments that is different from 1 it
should print "`Wrong number of arguments`".

## Input argument validation

Write a C program that `noAs` that given a string as argument, does
either of the following.

  * If the first character of the string is an the `char` `A` it
    prints "`No beginning A's are allowed`",

  * otherwise it prints the given string.

Reminder: Consider how strings are formatted in C.

Note: reuse your argument validation from before. You can just as well
learn it from the beginning. _Always sanitise your input._

## Multiple input formats

Modify the `dice` program developed at lecture to support `dN` as
alternative notation for `1dN`.  Hint: if one `sscanf()` fails, try
another.

## Guessing game

Write a C program that on startup generates a random number with
`rand()`, and then asks the user to guess it, answering either "too
low" or "too high" when the user guesses wrong.  Take care to handle
non-numeric user input in a sensible way.  _Always sanitise your
input._
