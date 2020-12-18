SECTION .data
	bluster times 1010 db 0x65
	EXIT_STATUS equ 54
SECTION .bss

SECTION .text
global _start
_start:
	push qword bluster
	
	mov rax, 60 
   	mov rdi, EXIT_STATUS
   	syscall
