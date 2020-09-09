# Exercises for 2020-09-09

Author: Michael Kirkedal Thomsen <kirkedal@acm.org>

These exercises will to give you some experience with using GDB.

---

## Play with GDB

Take some of the programs from last weeks exercises or perhaps even
the assignment and play around with GDB. Recreate a bug that you had
in your program and try finding it with GDB.  Test most of the
commands on the [GDB QUICK REFERENCE
sheet](https://sourceware.org/gdb/current/onlinedocs/refcard.pdf.gz)
(which can also be found in today's exercise folder).

## Debug some programs

[Attached](exercise_code/) there is a list of programs containing some
different bugs. Some of them very obvious. Use GDB to identify and
profile the bugs. Record your approach in a GDB script.

We recommend to investigate in the following order:

* `hello.c`
* `table.c`
* `capitalize.c`
* `array.c`

## Play with floating points

Integers are by now way too easy. Don't miss the [Floating point
game](https://games.onlineta.org/floating-point.html).
