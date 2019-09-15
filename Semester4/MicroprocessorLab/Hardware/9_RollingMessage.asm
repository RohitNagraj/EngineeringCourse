; @Author: Vybhav Jain
; @Last Modified by: Nimish Bongale

assume cs:code,ds:data
data segment
        pa equ 20a0h
        pb equ 20a1h
        pc equ 20a2h
        cr equ 20a3h
        msg db 71h, 9fh, 0f5h, 61h, 0ffh,71h, 9fh, 0f5h, 61h, 0ffh,71h, 9fh, 0f5h, 61h, 0ffh ; The message is "FIRE FIRE FIRE"
data ends

code segment
start: 
        mov ax,data
        mov ds,ax

        mov dx,cr
        mov al,80h
        out dx,al

        rpt:
                mov cx,15d      ; 15 is the message length
                lea si,msg

                nextchar:
                        mov al,[si]
                        call disp
                        call delay
                        inc si
                        loop nextchar
                        
                mov ah,06h      ; Check for keyboard interrupt
                mov dl,0ffh
                int 21h
                jz rpt          ; If none, repeat

        mov ah,4ch
        int 21h

        disp proc
                push cx
                mov cx,08
                nextbit:
                        mov dx,pb
                        out dx,al
                
                        push ax
                        
                        mov al,0ffh
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
                mov bx,07fffh
                l2:
                        mov di,07fffh
                        l1: 
                                dec di
                                jnz l1
                        dec bx
                        jnz l2
                ret
        delay endp
code ends
end start