# Exercises for 16/9-2020

Author: Michael Kirkedal Thomsen <kirkedal@acm.org>

## Understanding translations
  * 3.18 (BOH p 249)
    * Furthermore, rewrite the control flow to x86prime (use cbX instructions)
      * We assume that idivq exists
  * 3.23 (BOH p 258)
    * Furthermore, rewrite the control flow to x86prime (use cbX instructions)

## Decompilation
Rewrite the following program to C

```
p:
    subq $8, %rsp
    movq %r11, (%rsp)
    movq %rdi, %rax
    jmp .L2
.L3:
    addq %rsi, %rdx
    movq %rdx, (%rax)
    addq $8, %rax
.L2:
    movq (%rax), %rdx
    cbl $0, %rdx, .L3
    subq %rdi, %rax
    sarq $3, %rax
    movq (%rsp), %r11
    addq $8, %rsp
    ret %r11
```
