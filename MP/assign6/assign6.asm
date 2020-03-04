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

	msg1:db "content of GDTR are:"
	len1:equ $-msg1

	msg2:db "limit of GDTR is:"
	len2:equ $-msg2

	msg3:db "content of LDTR are:"
	len3:equ $-msg3

	msg4:db "content of IDTR are:"
	len4:equ $-msg4

	msg5:db "limit of IDTR is:"
	len5:equ $-msg5

	msg6:db "content of TR is:"
	len6:equ $-msg6

	msg7:db "content of MSW are:"
	len7:equ $-msg7

	msg8:db "Working in real mode"
	len8:equ $-msg8

	msg9:db "Working in protected mode"
	len9:equ $-msg9

	enter:db 0x0A
	cnt:db 0

	section .bss

	msw:resb 4
	res:resb 4
	gdt:resb 6
	idt:resb 6

	section .text

	global _start
	_start:
	main:

	smsw eax

	BT eax,0
	jnc down

	print msg9,len9
	print enter,1
	jmp next

down:
	print msg8,len8

next:
	print msg7,len7
	smsw eax
	mov dword[msw],eax
	mov rsi,msw+2
	mov ax,word[rsi]
	call htoa

	mov rsi,msw
	mov ax,word[rsi]
	call htoa

	print enter,1
	
	print msg3,len3
	sldt ax
	call htoa
	print enter,1

	print msg6,len6
	str ax
	call htoa
	print enter,1

	sgdt [gdt]
	print msg1,len1
	mov rsi,gdt+4
	mov ax,word[rsi]
	call htoa
	mov rsi,gdt+2
	mov ax,word[rsi]
	call htoa
	print enter,1
	
	print msg2,len2
	mov rsi,gdt
	mov ax,word[rsi]
	call htoa
	print enter,1

	sidt [idt]
	print msg4,len4
	mov rsi,idt+4
	mov ax,word[rsi]
	call htoa
	mov rsi,idt+2
	mov ax,word[rsi]
	call htoa
	print enter,1
	
	print msg5,len5
	mov rsi,idt
	mov ax,word[rsi]
	call htoa
	print enter,1


	jmp exit

htoa:

	mov rdi,res
	mov byte[cnt],4

up:
	rol ax,4
	mov bl,al
	and bl,0x0F
	cmp bl,09
	jbe next2
	add bl,07h
	
	
next2:
	add bl,30h
	mov byte[rdi],bl
	inc rdi
	dec byte[cnt]
	jnz up
	
	print res,4
	ret

exit:
	mov rax,60
	mov rdi,0
	syscall

	

