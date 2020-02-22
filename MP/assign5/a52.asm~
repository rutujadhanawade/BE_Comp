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

blanck db 00H
ent db 00H
count db 00H
;c1 db 00H
msg db 'enter letter u want to find::'
len equ $-msg

section .bss

extern lenght
extern buffer
letter resb 2
;blanck resb 2 dont do this;(
;ent resb 2

section .text
extern HtoA
global Enter
global Bspace
global cha

Bspace :
	mov rcx,[lenght]
	mov rsi,buffer
	;mov byte[blanck],00H
	
BS1:	cmp byte[rsi],20H
	jne BS2
	inc byte[blanck]
	;mov bl,byte[blanck]
BS2:    inc rsi
	loop BS1
	
	mov dx,[blanck]
	;print blanck,2
	call HtoA
	ret

Enter :
	mov rcx,[lenght]
	mov rsi,buffer
	;mov byte[ent],00H
	
E1:	cmp byte[rsi],0x0A
	jne E2
	inc byte[ent]
	;mov bl,byte[ent]
E2:  	inc rsi
	loop E1
	
	mov dx,[ent]
	call HtoA
	;print ent,4
	ret

cha :  print msg,len
	read letter,2
	xor rbx,rbx
	
	mov rcx,[lenght]
	mov rsi,buffer
	
ch1:	mov bl,[letter]
	cmp byte[rsi],bl
	jne ch2
	inc byte[count]
	
ch2:  	
	inc rsi
	loop ch1
	
	xor rdx,rdx
	mov dl,[count]
	call HtoA
	
	ret

