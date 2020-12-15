Section .data
   msg db "Ali Raza", 0xA
   EXIT_STATUS equ 54

Section .bss
;nothing here

SECTION .text
   global _start
   _start:
;display a message on stdout
      Mov Rax,1
      mov rdi,1 
      mov rsi,msg
      mov rdx,26
      Syscall    
;exit the program
      mov rax,60
      mov rdi,EXIT_STATUS
      syscall
