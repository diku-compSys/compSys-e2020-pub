# Compsys 2020 anti-stress guide #

Dear students,

We know that A2 is difficult, so we have agreed to create a small guide to help you in the right direction of solving this assignment.


## Pipeline Concept ##

Let's start with something simple..

Imagine having a pipeline for washing clothes. We have 2 pipeline stages - washing machine and a drying machine.
Let's denote these stages W (wash) and D (dry). One execution graph might look like this:

```
process   WD
process    WD
processl    WWD
process       WD
...
```

What is interesting to note here:
- we cannot have 2 washes (instructions) in one machine (stage) at the same time
- we can dry a wash only when it's finished washing
- if we wash with the special 'super long program', the wash takes 2 cycles, and thus we would have to stall the W stage.

Why is this interesting?
Because the exact same principles apply to our A2 architecture. Imagine having a program which executes like this:

```
load   FXM         # movq (%eax), %r12
use     FXXM       # cbe %0, %r12, .L3
```

Here we need to stall the X stage until we have finished loading from memory, because the data is being used in the following
instruction. This is what we call a 'data hazard',


## Relation to the code ##

In the `control_pipeline` function we have a number of arguments for our function. You will really need to look at the data structures
of these arguments. There is a very good drawing of the pipeline architecture in the assignment description.
It is a prerequisite to understand this drawing before you program anything. Start slow: Create a couple of (VERY) simple prime-assembly
programs and use prun to run them. To compare with your simulator use a tracefile. Write execution graphs in hand of these programs
to strengthen your intuition of how to pipeline works.

The `control_pipeline` function controls the pipeline (hence the name). It does this by signalling the different pipeline stages,
e.g. by stalling X on data hazards, or by throwing out instructions from F when a jump is taken.
The input arguments correspond to what is in the registers between the stages, as well as events that should be taken into account.
Currently, all pipeline stages are signalled to run by explicitly being set to `true`; it is your job to figure out what to write instead.


## But what, how? ##

Remember the example with the clothes washing pipeline: We cannot start the drying machine if it is not yet finished.
So e.g., if we should determine whether or not to run X, then we must make sure that M can run - otherwise we would override
the load/store registers! The following is a strong hint, and an example of how to approach your task:

```
result.compute_runs = result.load_store_runs && !data_hazard;
```

You then need to figure out how to check for data hazards.

Remember, an instruction cannot enter a stage unless that stage is finished processing the previous instruction.

Keep in mind - this assignment is about a concept. Do not expect to get a magic solution in your head from staring at the code.
You will likely better spend your time in understanding how the pipeline behaves by drawing execution diagrams. A good source for
reading material on this is found [here](https://x86prime.github.io/afviklingsplot/).


## Q/A ##

- Should I attempt to decode the instruction in `control_pipeline` - NO!
- Should I use loops/if-else/switch in `control_pipeline` - NO!
- Should I use `control_pipeline` to signal the pipeline stages - YES!
- Does it take 2 cycles to load from memory - YES!


## Tools ##

This is a complete cheat sheet of our programs and their interactions:

```
        (gcc)          (primify)             (prasm)         (prun/sim)
file.c  ----->  file.s  ------>  file.prime   ---->  file.hex  ------> simulate!

```
Alternatively, you may want to use the online tools
(gcc-online.py, primify.py, ...) if you were not able to build these tools yourself.

#### Note ####

We recommend that you write your test programs **directly** in prime assembly. We
recommend this because it is much easier and faster!
GCC and primify are only included here for the sake of completeness, and because
they can be useful for getting you started on writing prime assembly.


## Report ##

You are asked to draw an execution graph (afviklingsplot) to verify that your
implementation works as expected. This program should be written directly
in prime assembly, and does not have to perform any meaningful computations.
We do not care about its details, only that your implementation will
stall/change IP correctly (IP = Instruction Pointer).

You are also required to create a bunch of test scripts - do not spend time
on creating meaningful programs. Simply write stuff directly in prime
assembly to show that the pipeline works correctly.


## Panic ##

Arghh.. what is a pipeline? What is assembly code? What does 'ALU' mean? Why do we need an instruction pointer?
Why are we using a pipeline, instead of just a simple processor with no pipeline stages? What is a register?
I don't understand the drawing in A2 assignment paper?

Answer to all these questions can be found in the lectures, located in absalon -> Computersystemer -> Media Gallery.
Take a look at Finn's slides for 21/23 Sept.
