%macro print 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro read 2
        mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro
;;;; overlapping witrhout string	
section .data
	colon: db " : "
	len1: equ $-colon
	newl: db 0xA
	len2: equ $-newl	
	msg3: db "The original array is :-", 10
	len3: equ $-msg3
	msg4: db "The final array is :-", 10
	len4:  equ $-msg4
	msg5: db "enter offset :-", 10
	len5:  equ $-msg5
	
	arr: dq 1,2,3,4,5

section .bss
cnt resb 4
cnt2 resb 4
result: resb 20
offset resb 8

section .data
global _start
_start:
	print msg3,len3
	
	; printing the array
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
	
	
; copying data to another location
	mov rsi, arr
	mov rdx, arr + 80
	mov byte[cnt], 5

up2:
	mov rbx, qword[rsi]
	mov qword[rdx], rbx
	
	add rsi, 8
	add rdx, 8
	dec byte[cnt]
	jnz up2 

	print msg5,len5
	read offset,8
	;mov rsi,offset
	;mov rdx,rsi
	;call HtoA
	;l: add al,8
	;    dec offset
	 ;   jnz l
	
; copying data - overlapping
	
	mov rsi, arr + 80
	
	mov rdx, arr + 32
	mov byte[cnt], 5
up5:
	mov rbx, qword[rsi]
	mov qword[rdx], rbx
	
	add rsi, 8
	add rdx, 8
	dec byte[cnt]
	jnz up5

	
	print newl,1
	
;final
; printing the array

	print msg4,len4
	
	mov rsi, arr
	mov byte[cnt], 10
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

