# Exercise solution for 16/9-2020

Author: Michael Kirkedal Thomsen <kirkedal@acm.org>

## Decompilation
Rewrite the following program to C

```
 1  p:
 2      subq $8, %rsp
 3      movq %r11, (%rsp)
 4      movq %rdi, %rax
 5      jmp .L2
 6  .L3:
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
10  .L2:
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3
13      subq %rdi, %rax
14      sarq $3, %rax
15      movq (%rsp), %r11
16      addq $8, %rsp
17      ret %r11
```

### Solution

When answering a question always give arguments for your decided program. Start from "pealing" the program from the outside. The following answers it very methodically, very step-by-step. You are not expected to do this, but it should show my thoughts of the decompilation.

#### First, name of the function
  * The top label is `p`.
  * Also notice we have the x86prime pusing (lines 2-3) and popping (lines 15-16) of the return address, so we are expected to enter here.
    * We can with good concision ignore these as they are handled by the compiler. And the `%r11` can be removed to avoid any confusion, if we were using the register through our program.


Below I will use a mixed C/x86prime programming style and remove lines as I translate them to C:

```
... p (...) {

 4      movq %rdi, %rax
 5      jmp .L2
 6  .L3:
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
10  .L2:
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3
13      subq %rdi, %rax
14      sarq $3, %rax
17      ret

}
```

#### Number of argument
  * First time we are using `%rdi`(line 4) we read, thus we have at least 1 argument
  * Only time we are using `%rsi` (line 7), second argument register, we are reading from it, thus we have at least 2 arguments
  * First time we are using `%rdx`, third argument register, we are writing to it. That is actually in line 11, as we are jumping to label `.L2`. Thus this cannot have been used for inputs.
  * We can therefore conclude that there are two inputs to out function.

I rename all my `%rdi` for `a1` and for the moment add name scopes in curly brackets. `%rsi` to `a2`:

```
... p (... a1, ... a2) {

{%rdi -> a1, %rsi -> a2 }

 4      movq %rdi, %rax
 5      jmp .L2
 6  .L3:
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
10  .L2:
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3
13      subq %rdi, %rax
14      sarq $3, %rax
17      ret

}
```

#### Type of the first argument
  * Generally we are only using 64-bit versions of the instructions, so we can conclude that it is a `long`.
  * The first time we are using `%rdi` we write its content to `%rax`, which does not give any useful information.
  * However, first time we are using `%rax` (line 11) we are using `%rax` to read from memory (`movq (%rax), %rdx`).
  * Hence `%rdi` must contain an address and thus be a pointer.

```
... p (long *a1, ... a2) {

[assembly code]

}
```

#### Type of the second argument
  * We are only using `%rsi` to add to `%rdx` and `%rdx` is only used for writes and arithmetic.
  * Hence `%rsi` can be expected to be a `long`.

```
... p (long *a1, long a2) {

{%rdi -> a1, %rsi -> a2 }

 4      movq %rdi, %rax
 5      jmp .L2
 6  .L3:
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
10  .L2:
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3
13      subq %rdi, %rax
14      sarq $3, %rax
17      ret

}
```


#### Initial phase of the body
  * Line 4 is only this that happened before the first control instruction (`jmp` in line 4).
  * Here I move the first input to `rax`.
  * Hence, I can create a new variable of the same type as the first argument. 
  * I will call it `tmp1` and rename the `%rax`

```
... p (long *a1, long a2) {
  long *tmp1 = a1;

{%rdi -> a1, %rsi -> a2, %rax -> tmp1 }

 5      jmp .L2
 6  .L3:
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
10  .L2:
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3
13      subq %rdi, %rax
14      sarq $3, %rax
17      ret

}
```

#### Finding control structures
  * On the course we will meet two fundamental different control structures: conditionals and loops. Remember, (from our standard translation):
    * conditionals will jump to different parts of the code, but always continue forward
    * loops will jump back to be able to execute a loop-body several times.
  * Here `cbl` in line 12 jumps back to `.L3` and we can loop. We have basically three kinds for loops:
    * do-while: falls though a label to execute the body, then jumps back over the body.
    * while-do: jump over the body (with top label) to a label in the condition. After this a do-while.
    * for-loop: an initiation phase followed by a while-do
  * Here we can annotate the program as: 

```
... p (long *a1, long a2) {
  long *tmp1 = a1;

{%rdi -> a1, %rsi -> a2, %rax -> tmp1 }

 5      jmp .L2               # Jump over a label to a later one, thus to the loop condition
 6  .L3:                      # Loop body start
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
10  .L2:                      # Loop condition start
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3     # Jump back, hence there is a loop body
13      subq %rdi, %rax
14      sarq $3, %rax
17      ret

}
```
  * We can from the above see that there is a while-do loop and defined it like

```
... p (long *a1, long a2) {
  long *tmp1 = a1;

{%rdi -> a1, %rsi -> a2, %rax -> tmp1 }

  while (
11      movq (%rax), %rdx
12      cbl $0, %rdx, .L3
    ) {
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
  }

13      subq %rdi, %rax
14      sarq $3, %rax
17      ret
}
```

#### Loop condition
  * To find the correct loop condition we can update `cbl $0, %rdx, .L3` to the expected `0 < %rdx`
    * Note for conditionals we have the negated condition, but not for loops.
  * Line 11 must be performed just before each check of the condition, so we will duplicate this and have is just before entering the loop and at the end of the loop body.


```
... p (long *a1, long a2) {
  long *tmp1 = a1;

{%rdi -> a1, %rsi -> a2, %rax -> tmp1 }

11      movq (%rax), %rdx
  while (0 < %rdx) {
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
11      movq (%rax), %rdx
  }

13      subq %rdi, %rax
14      sarq $3, %rax
17      ret
}
```

#### First write to `%rdx`
  * In line 11 we make the first write to `%rdx`, by reading the value that tmp1 point to.
  * Hence, as `tmp1` is a long pointer (the value that is on the address of `tmp1` is a long), `%rdx` is of type `long`. Lets call it `tmp2`
  * I will define `tmp2` in the beginning and update the first usage


```
... p (long *a1, long a2) {
  long *tmp1 = a1;
  long tmp2 = *tmp1;
{%rdi -> a1, %rsi -> a2, %rax -> tmp1, %rdx -> tmp2}

  while (0 < %rdx) {
 7      addq %rsi, %rdx
 8      movq %rdx, (%rax)
 9      addq $8, %rax
11      movq (%rax), %rdx
  }

13      subq %rdi, %rax
14      sarq $3, %rax
17      ret
}
```

#### Other updates and usages of `%rdx`
  * The loop contains 4 references to `%rdx` and we can update these the stright forward with `tmp2`
  * also remove the `%rsi`

```
... p (long *a1, long a2) {
  long *tmp1 = a1;
  long tmp2 = *tmp1;
{%rdi -> a1, %rax -> tmp1}

  while (0 < %rdx) {
   tmp2 += a2;
   *tmp1 = tmp2;
 9      addq $8, %rax
   tmp2 = *tmp1;
  }

13      subq %rdi, %rax
14      sarq $3, %rax
17      ret
}
```

#### Pointer arithmetic
  * Remember that `tmp1` is a pointer to a `long`; say points to an element of an array of longs. When we increment a pointer (by 1), we conceptually want to choose the next element of the array.
  * Addresses in the machine are always indexed in byte size.
  * Hence when we in out C code increment a pointer `tmp1` (like `tmp1++`) it will show in our assembly code as an addition by 8!
    * A `long` is 8 bytes, therefore the next element of the array will be 8 bytes further along.
  * Thus, `addq $8, %rax` is just incrementing `tmp2` by one.


```
... p (long *a1, long a2) {
  long *tmp1 = a1;
  long tmp2 = *tmp1;
  while (0 < tmp2) {
   tmp2 += a2;
   *tmp1 = tmp2;
   tmp1++;
   tmp2 = *tmp1;
  }

{%rdi -> a1, %rax -> tmp1}

13      subq %rdi, %rax
14      sarq $3, %rax
17      ret
}
```

#### pointer arithmetic 2
  * Remember again that `%rdi` are `%rax` addresses pointing to longs.
  * Thus when we subtract `%rdi` from `%rax` we get the difference in addresses.
  * Therefore, this difference is 8 times higher than the number longs that can be placed in this address space.
  * Remember that right shifting thrice is equal to dividing by 8 (2^3 = 8).
  * Hence, the two instructions in lines 13 and 14 are subtracting the two pointers.
  * Note, that subtracting two addresses is a difference and not another address. Thus I create a new `tmp3` for `%rax` as a long.

```
... p (long *a1, long a2) {
  long *tmp1 = a1;
  long tmp2 = *tmp1;
  while (0 < tmp2) {
   tmp2 += a2;
   *tmp1 = tmp2;
   tmp1++;
   tmp2 = *tmp1;
  }
  long tmp3 = tmp1 - a1;

{%rax -> tmp3}
17      ret
}
```

#### Return value
  * Finally, we always return `%rax`.
  * This is now `tmp3` which is a long.


```
long p (long *a1, long a2) {
  long *tmp1 = a1;
  long tmp2 = *tmp1;
  while (0 < tmp2) {
   tmp2 += a2;
   *tmp1 = tmp2;
   tmp1++;
   tmp2 = *tmp1;
  }
  long tmp3 = tmp1 - a1;
  return tmp3;
}
```

#### The program
This is the program I used to generate the assembly code. At a glance it looks significantly different from the above, but can be rewritten to look similar. Mainly note that `tmp2` is always equal to the value that `tmp1` points to.

Shifts each element in a 0-terminated array with a given number and returns the number of elements in the array:

```
long array_inc(long *args, long disp) {
    long* start = args;
    while (*args > 0) {
        *args += disp;
        args++;
    }
    return args-start;
}
