	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 14
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	movl	$1, %eax
	retq
	.cfi_endproc

	.comm	_global.var.a,4,2       ## @global.var.a

.subsections_via_symbols
