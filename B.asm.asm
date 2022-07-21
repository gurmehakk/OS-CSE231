
extern C

section .data
  x db "In B",10
section .bss
  y resb 8
section .text
  global B

B:
	mov [y],rdi
  mov rax :1 
  mov rdi :1 
  mov rsi, x
  mov rdx ,10
  syscall
  call _printB
  push  C
_printB:
   ; mov rax : 1
     ;mov rdi :1 
     ;mov rsi ,y
     ;mov rdx ,8
           ret