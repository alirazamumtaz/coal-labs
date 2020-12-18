SECTION .data
	var1 dd 0x80424687
	var2 dq 0x00007fffffffdee8
SECTION .bss

SECTION .text
global _start
_start:
	mov rax, [var1]
	mov rbx, [var2]
	mov rax, 60
	mov rdi, 0
	syscall


