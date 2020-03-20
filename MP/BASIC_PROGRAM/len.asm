section .data
msg db "enter name:", 0xA
len equ $ - msg


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

	mov al,len1
	dec al
	
	
	
	
	mov rax,01
	mov rdi,01
	mov rsi,name
	mov rdx,10
	
	syscall



	mov rax,60
	mov rdi,0
	syscall

