# Exercises for 14/9-2019

Author: Michael Kirkedal Thomsen <kirkedal@acm.org>

These exercises will:
* Recap basic instructions
* Translation of C to assembler and x86prime
* Work with assembler in C

## Memory calculation and operation on register file
* BOH 3.1  (page 218)
* BOH 3.2  (page 221)
* BOH 3.3  (page 222)
* BOH 3.8  (page 230)

## Understanding translations
* BOH 3.5  (page 225)
* BOH 3.10 (page 232)
* BOH 3.11 (page 233)

### More compilation quirks
`a_sum.c` is a simple function calculating five times the sum of a `0` terminated list of `long`s using pointer arithmetic. Using `x86prime`, this is translated into x86prime assembly code in `a_sum.prime`. 
* Locate the non-control statements of `a_sum.c` (lines 4, 5, 7, 8 and 9) in `a_sum.prime`. For each, what differs from the expected translation and try to consider why?

Remember that:
  - function parameter registers are `%rdi`, `%rsi`, and so on (BOH p. 216).
  - return value register is `%rax` (BOH p. 216).
  - in x86prime, %r11 is the return address register.

Note: for now, please ignore lines 3-4 and 15-16 of `a_sum.prime`, as these instructions relate to the stack pointer, which we will save for later.
