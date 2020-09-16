	.file	"caaee660226dddb4bbcf52b2065f65b0.c"
	.text
	.globl	sumOfTwoFirst
	.type	sumOfTwoFirst, @function
sumOfTwoFirst:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rdx
	leaq	0(,%rdx,8), %rax
	subq	%rdx, %rax
	movq	8(%rdi), %rdx
	leaq	(%rdx,%rdx,4), %rdx
	addq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	sumOfTwoFirst, .-sumOfTwoFirst
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
