  .type decode1, @function
  .cfi_startproc
decode1:
  movq  (%rdi), %r8
  movq  (%rsi), %rcx
  movq  (%rdx), %rax
  movq  %r8, (%rsi)
  movq  %rcx, (%rdx)
  movq  %rax, (%rdi)
  ret
  .cfi_endproc
