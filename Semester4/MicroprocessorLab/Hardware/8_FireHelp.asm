; @Author: Piyush Mehta

assume cs:code, ds:data
data segment
pa equ 20a0h
pb equ 20a1h
pc equ 20a2h
cr equ 20a3h


fire db 71h,9fh,0f5h,061h
help db 0d1h,061h,0e3h,031h

;fire db 61h,0f5h, 9fh, 071h , to print in mirror image
;help db 031h,0e3h, 061h,0d1h

data ends

code segment
start:
        mov ax,data
        mov ds,ax

        mov dx,cr
        mov al,80h    ;activate the hardware
        out dx,al
        
rpt: 
        mov cx,04
        lea si,fire

nextchar:
        mov al,[si]
        call disp
        inc si
        loop nextchar
       ;call disp
        call delay

       mov cx,04      ; help
       lea si, help
  next: 
        mov al,[si]
        call disp
        inc si
        loop next
        call delay
       
         mov ah, 06h            ;Keyboard  input
         mov dl,0ffh            ; Don't wait for input
         int 21h

         jz rpt                 ;continuous loop if no key pressed
         
         mov ah,4ch
         int 21h

disp proc
        push cx
        mov cx,08       ; 8 segments
nextbit:
        mov dx,pb
        out dx,al
        push ax

        mov al, 0ffh
        mov dx,pc
        out dx,al

        mov al,00h
        out dx,al
        pop ax

        ror al,1
        loop nextbit
        pop cx
        ret
        disp endp

 delay proc
        mov bx,02fffh
        l2:mov di,0ddffh
        l1:dec di
           jnz l1
           dec bx
           jnz l2
           ret
 delay endp

 code ends
 end start