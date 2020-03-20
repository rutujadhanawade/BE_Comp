
section .data
msg db "hello", 0Ax
len equ $ - msg
cnt db 5

section .bss
name resb 10


section .text
global _start

_start:
	mov rax,01
	mov rdi,01
	mov rsi,msg
	mov rdx,len
	syscall

	mov rax,00
	mov rdi,00
	mov rsi,name
	mov rdx,10
	syscall
	
loop:	
	mov rax,01
	mov rdi,01
	mov rsi,name
	mov rdx,10
	syscall
        dec byte[cnt]
	jnz loop 


	mov rax,60
	mov rdi,0
	syscall



