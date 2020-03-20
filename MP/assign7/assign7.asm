	%macro print 2
	mov rax,1
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro
	
	%macro read 2
	mov rax,0
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	%endmacro


section .data

menu db " ---------------------------- " , 10
     db "            MENU              " , 10
     db " ---------------------------- " , 10
     db " 1) Ascending order " , 10
     db " 2) Decending order " , 10
     db " 3) Exit " , 10
     db "    Enter your choice " , 10
lmenu equ $-menu

file db "sort.txt",0
msg db "The sorted array in ascending order is",0xA
len equ $-msg

msg1 db "The original array is",0xA
len1 equ $-msg1

msg2 db "File opened successfully",0xA
len2 equ $-msg2

msg3 db "Error opening file",0xA
len3 equ $-msg3

msg4 db "The sorted array in descending order is",0xA
len4 equ $-msg4

newline db 10

section .bss

fin resq 1
var resb 100
varlen resq 1
count resb 1
count1 resb 1
result resb 1
choice resb 2

section .text

global _start

	_start:


	mov rax,2
	mov rdi,file
	mov rsi,2
	mov rdx,777
	syscall
		
	mov qword[fin],rax	
	bt rax , 63
 	jc tag
  	print msg2 , len2
  	jmp read_f
	tag : print msg3 , len3



	read_f:
	
	mov rax,0
	mov rdi,[fin]
	mov rsi,var
	mov rdx,100
	syscall
	
	mov qword[varlen],rax	
	print msg1,len1
	print var,[varlen]
	print newline,1
	


	main:
	print menu,lmenu
	print newline,1
	
	read choice,2
	
	cmp byte[choice] , 31h
        je ascending
 
        cmp byte[choice] , 32h
        je decending
        
        cmp byte[choice] , 33h
        jae exit


	
	ascending :

   mov byte[count] , 05

tag1: mov rsi , var
      mov rdi , var + 1
      mov byte[count1] , 04
label : mov al , byte[rsi]
        cmp al , byte[rdi]
        ja label2
        add rsi , 01
        add rdi , 01
        dec byte[count1]
        jnz label
        jmp tag2
label2 : mov al , byte[rsi]
         mov dl , byte[rdi]
         mov byte[rsi] , dl
         mov byte[rdi] , al
         add rsi , 01
         add rdi , 01
         dec byte[count1]
         jnz label 

tag2 :           
      dec byte[count]
      jnz tag1
      
      ;-------------printing asc array------------
	print msg,len
	print var,varlen
	
	;-------------writing msg to file(asc)------------
	mov rax,01
	mov rdi,[fin]
	mov rsi,msg 
	mov rdx,len
	syscall
	
	;-------------writing sorted array to file(asc)------------
	mov rax,01
	mov rdi,[fin]
	mov rsi,var 
	mov rdx,[varlen]
	syscall
	
	jmp main
;------------------bubble sorting array in descending order-----------------

	decending :
     mov byte[count] , 05

tag3: mov rsi , var
      mov rdi , var + 1
      mov byte[count1] , 04
label3 : mov al , byte[rsi]
        cmp al , byte[rdi]
        jbe label4
        add rsi , 01
        add rdi , 01
        dec byte[count1]
        jnz label3
        jmp tag4
label4 : mov al , byte[rsi]
         mov dl , byte[rdi]
         mov byte[rsi] , dl
         mov byte[rdi] , al
         add rsi , 01
         add rdi , 01
         dec byte[count1]
         jnz label3 

tag4 :           
      dec byte[count]
      jnz tag3
	
	;-------------printing des array------------
	print msg4,len4
	print var,varlen
	
	;-------------writing msg to file(des)------------
	mov rax,01
	mov rdi,[fin]
	mov rsi,msg4
	mov rdx,len4
	syscall
	
	;-------------writing sorted array to file(des)------------
	mov rax,01
	mov rdi,[fin]
	mov rsi,var 
	mov rdx,[varlen]
	syscall
	
	jmp main
;--------------close a file---------------

	mov rax,3
	mov rdi,[fin]
	syscall
	
;------------exit system call--------------


	exit:
	mov rax,60
	mov rdi,0h
	syscall
