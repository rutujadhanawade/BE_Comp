%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
file_name db 'a5.txt',0
msg1 db 'no.of blanck spaces is:',0xA
len1 equ $-msg1
msg2 db 'no of enter in text file:',0xA
len2 equ $-msg2
msg3 db 'no of ocurance of char is:',0xA
len3 equ $-msg3
msg4 db 'file is closed',0xA
len4 equ $-msg4
msg5 db 'file open',0xA
len5 equ $-msg5
newl db 0x0A

section .bss
global buffer
;extern ent
global lenght
num resb 4
fd resb 8
lenght resb 20
buffer resb 20
count resb 2
cnt2 resb 2
result resb 8

section .text
extern Bspace
extern Enter
extern cha
global HtoA
global _start

_start:


mov rax,02
mov rdi,file_name
mov rsi,02
mov rdx,0777
syscall

mov [fd],rax
BT rax,63
jc next
print msg5,len5
jmp ll
next:
print msg4,len4

ll:
mov rax,0
mov rdi,[fd]
mov rsi,buffer
mov rdx,100
syscall

mov [lenght],rax
;mov dx,[lenght]
;call HtoA


print buffer, lenght

print msg1,len1
call Bspace


print msg2,len2
call Enter

print msg3,len3
call cha



mov rax,60
mov rdi,60
syscall

HtoA:
	mov rdi, result
	mov byte[cnt2], 4	
	
up1:     ; dx is storing hex and result storing ascii
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
	print newl,1
RET

