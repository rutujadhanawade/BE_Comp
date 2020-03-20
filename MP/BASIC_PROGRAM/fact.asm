%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro
%macro read 2
     	  mov rax,00
	  mov rdi,01
	  mov rsi,%1
	  mov rdx,%2
          syscall
          
%endmacro

section .data
	msg1:db "enter number:"
	len1:equ $-msg1

	msg2:db "factorial is:"
	len2:equ $-msg2
cnt db 00H
section .bss
num: resb 2
val: resb 2
result: resb 4
cnt2: resb 2

section .text
global _start
_start:
	print msg1,len1
	read num,2
	call AtoH
l1:	cmp byte[num], '1'
	je l2
	
	push word[num]
	inc byte[cnt]
	dec byte[num]
	jnz l1
	
	mov rax ,01H
l2:	pop [bx]
	mul bx
	dec byte[cnt]
	jnz l2

	
;	mov rcx,rax
;	xor rax,rax
;	mov rax,01H
;	xor rdx,rdx
;	
;l2:	print msg2,len2
;	mul rcx
;	;loop l1
;	
;	;mov dx,ax
	call HtoA
	
	
	
	
exit:
mov rax,60
mov rdi,60
syscall

HtoA:
	mov rdi, result
	mov byte[cnt2], 4	
	
up1:
	rol ax, 4
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
	mov rsi,num
	mov byte[cnt2],2
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

	
