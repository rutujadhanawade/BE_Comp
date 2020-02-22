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
	colon: db " : "
	len1: equ $-colon
	newl: db 0xA
	len2: equ $-newl	
	msg3: db "-", 10
	len3: equ $-msg3
	msg4: db "The final array is :-", 10
	len4:  equ $-msg4
	arr: dq 1,2,3,4,5,0,0,0,0
	
section .bss
cnt resb 5
cnt2 resb 5
result: resb 20
off resb 1

section .data
global _start
_start:
	print msg3,len3
	
	;;;;;;;;; printing the array
	mov rsi, arr
	mov byte[cnt], 5

up1:
	mov rdx, rsi
	push rsi
	call HtoA
	
	print colon,1

	pop rsi
	
	mov rdx, qword[rsi]
	push rsi
	call HtoA
	
	print newl,1
	
	pop rsi
	
	add rsi, 8
	dec byte[cnt]
	jnz up1
	

	read off,1

	mov ax,[off]
	SUB ax,30H
 	mov bx,08
	mul bx
	;mov [off],eax
	
	mov rsi, arr +32
	mov rdx, arr +32
	add rdx,rax
	
	mov byte[cnt], 5

up2:
	mov rbx, qword[rsi]
	mov qword[rdx], rbx
	
	sub rsi, 8
	sub rdx, 8
	dec byte[cnt]
	jnz up2 

	
	print newl,1
	
;final


	print msg4,len4
	
	mov rsi, arr

	mov ax,[off]
	sub ax,30H
	add ax,5
	mov word[cnt], ax
up4:
	mov rdx, rsi
	push rsi
	call HtoA
	
	print colon,1

	pop rsi
	mov rdx, qword[rsi]
	push rsi
	call HtoA
	
	print newl,1
	
	pop rsi
	add rsi, 8
	dec byte[cnt]
	jnz up4
	
	mov rax,60
	mov rdi,60
	syscall
	

; Hex to ascii conversion
HtoA:
	mov rdi, result
	mov byte[cnt2], 16	
	
up3:
	rol rdx, 04
	mov cl, dl
	AND cl, 0FH
	cmp cl, 09H
	jbe next2
	add cl, 07H
next2:
	add cl, 30H
	
	mov byte[rdi], cl
	inc rdi
	dec byte[cnt2]
	jnz up3
		
	mov rax, 1
	mov rdi, 1
	mov rsi, result
	mov rdx, 16
	syscall

RET
	
	



