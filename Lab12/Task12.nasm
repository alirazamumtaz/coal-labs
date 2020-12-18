SECTION .data
	num1 dd 0x41414141
	num2 dq 0x42424242
	EXIT_STATUS equ 0

SECTION .bss   

SECTION .text
global _start
_start:	
	mov esi, num1
	mov eax, [esi]
	mov edi, num2
	mov edx, [edi]
	mov [esi], edx
	mov [edi], eax
	
   mov rax, 60 
   mov rdi, EXIT_STATUS
   syscall
