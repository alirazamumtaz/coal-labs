; res = num1 + num1 - num2


SECTION .data
	num1 db 0x4
	num2 db 0x32
	EXIT_STATUS equ 54
SECTION .bss
	res: resb 64

SECTION .text
global _start
_start:
	ADD num1, num1
	SUB num1, num2
	mov res, num1	
	 push qword [res]
	 
	 
	mov rax, 60 
   	mov rdi, EXIT_STATUS
   	syscall
