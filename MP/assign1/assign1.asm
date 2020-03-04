%macro print 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data
array : dq 0x10,0xAB,0x98,0x11,0x12
msg1 db "enter ",0Ax
len equ $ - msg1
cnt db 10
cnt1 db 10

section .bss


section .text
global _start
	
_start:
	mov rsi,array
	
up: 	
	
	mov rax,00
	mov rdi,00
	mov rsi,array
	mov rdx,10
	syscall
  	dec byte[cnt]
	jnz loop 
	
loop1:
	mov rax,01
	mov rdi,01
	mov rsi,array
	mov rdx,10
	syscall
	 dec byte[cnt1]
	jnz loop1 
	
	mov rax,60
	mov rdi,00
	syscall
