	.file	"0b93edeca53a44db475acf9640f99c10.c"
	.text
	.globl	weightedSumOfTwo
	.type	weightedSumOfTwo, @function
weightedSumOfTwo:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rdx
	leaq	0(,%rdx,8), %rax
	subq	%rdx, %rax
	movl	%esi, %esi
	movq	(%rdi,%rsi,8), %rdx
	leaq	(%rdx,%rdx,4), %rdx
	addq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	weightedSumOfTwo, .-weightedSumOfTwo
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
