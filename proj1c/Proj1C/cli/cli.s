	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_Usage
	.align	4, 0x90
_Usage:                                 ## @Usage
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rcx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movq	%rcx, %rsi
	callq	_printf
	leaq	L_str(%rip), %rdi
	popq	%rbp
	jmp	_puts                   ## TAILCALL
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
Ltmp6:
	.cfi_offset %rbx, -32
Ltmp7:
	.cfi_offset %r14, -24
	movq	%rsi, %r14
	cmpl	$3, %edi
	jne	LBB1_13
## BB#1:
	movq	8(%r14), %rbx
	leaq	L_.str.2(%rip), %rsi
	movq	%rbx, %rdi
	callq	_strcmp
	testl	%eax, %eax
	je	LBB1_2
## BB#3:
	leaq	L_.str.3(%rip), %rsi
	movq	%rbx, %rdi
	callq	_strcmp
	testl	%eax, %eax
	je	LBB1_4
## BB#5:
	leaq	L_.str.4(%rip), %rsi
	movq	%rbx, %rdi
	callq	_strcmp
	testl	%eax, %eax
	je	LBB1_6
## BB#7:
	leaq	L_.str.5(%rip), %rsi
	movq	%rbx, %rdi
	callq	_strcmp
	testl	%eax, %eax
	je	LBB1_8
## BB#9:
	leaq	L_.str.6(%rip), %rsi
	movq	%rbx, %rdi
	callq	_strcmp
	testl	%eax, %eax
	jne	LBB1_12
## BB#10:
	movq	_log330@GOTPCREL(%rip), %rbx
	jmp	LBB1_11
LBB1_2:
	movq	_cos330@GOTPCREL(%rip), %rbx
	jmp	LBB1_11
LBB1_4:
	movq	_sin330@GOTPCREL(%rip), %rbx
	jmp	LBB1_11
LBB1_6:
	movq	_tan330@GOTPCREL(%rip), %rbx
	jmp	LBB1_11
LBB1_8:
	movq	_exp330@GOTPCREL(%rip), %rbx
LBB1_11:
	movq	16(%r14), %rdi
	callq	_atof
	callq	*%rbx
	leaq	L_.str.8(%rip), %rdi
	movb	$1, %al
	callq	_printf
	xorl	%eax, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
LBB1_12:
	leaq	L_.str.7(%rip), %rdi
	xorl	%eax, %eax
	movq	%rbx, %rsi
	callq	_printf
LBB1_13:
	movq	(%r14), %rdi
	callq	_Usage
	movl	$1, %edi
	callq	_exit
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Usage: %s command value\n\n"

L_.str.2:                               ## @.str.2
	.asciz	"cos"

L_.str.3:                               ## @.str.3
	.asciz	"sin"

L_.str.4:                               ## @.str.4
	.asciz	"tan"

L_.str.5:                               ## @.str.5
	.asciz	"exp"

L_.str.6:                               ## @.str.6
	.asciz	"log"

L_.str.7:                               ## @.str.7
	.asciz	"Invalid command: %s"

L_.str.8:                               ## @.str.8
	.asciz	"%f\n"

	.align	4                       ## @str
L_str:
	.asciz	"Valid commands are:\tcos, sin, tan, exp, log"


.subsections_via_symbols
