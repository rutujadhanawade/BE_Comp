%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro read 2
mov rax,00
mov rdi,00
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
msg1: db "1.Successive addition",0xA
      db "2.Add and Shift Method.",0xA
      db "3.EXIT", 0xA
len1 equ $-msg1

section .bss
opt resb 06
val resb 10
a resb 10
b resb 10
result resb 10
cnt resb 01
cnt2 resb 01

section .text
global _start
_start:

menu:
	print msg1,len1
	read opt,2

	cmp byte[opt],'1'
	je S_A

	;cmp byte[opt],'2'
	;je H_B
	

S_A :	read val,05
	call AtoH
	mov [a],bx
	
	xor rbx,rbx
	read val,05
	call AtoH
	mov [b],rbx
	xor rax,rax
	;mov ax,word[a]
	xor rcx,rcx
	mov rcx,[b]

l1:	add ax,word[a]
	loop l1
	
	xor rdx,rdx
	mov dx,ax
	call HtoA
	call exit

add_shift: read val,03
	   	call AtoH	
	mov [a],bx
	
	read val,03
	call AtoH
	mov [b],bx
	
	xor rbx,rbx
	xor rcx,rcx
	mov bl,[a]
	mov cl,[b]
	xor rax,rax
	mov byte[cnt],08H
	
l2: 	shl bl,1
	jnc l3
	add rax,rcx
	
l3: 	shl rax,1
	dec byte[cnt]
	jnz l2
	
	xor rdx,rdx
	mov rdx,rax
	call HtoA

exit:
mov rax,60
mov rdi,60
syscall

HtoA:
	mov rdi, result
	mov byte[cnt2], 4	
	
up1:
	rol dx, 4
	mov cl, dl
	AND cl, 0FH
	cmp cl, 09H
	jbe next1
	add cl, 07H
next1:
	add cl, 30H
	
	mov byte[rdi], cl
	inc rdi
	dec byte[cnt2]
	jnz up1
		
	print result,4

RET

AtoH:
	mov rsi,val
	mov byte[cnt2],4
	xor rbx,rbx
up2:  
	rol bx,4
	mov al,byte[rsi]
	cmp al,39H
	jbe next2
	sub al,07H
	
next2:
	sub al,30H
	add bx,ax
	inc rsi
	dec byte[cnt2]
	jnz up2
	
RET


