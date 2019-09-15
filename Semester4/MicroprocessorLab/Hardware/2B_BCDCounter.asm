; @Author: Nimish Bongale
; @Last Modified by: Rohit Nagraj

assume cs:code,ds:data
data segment
        pa equ 20A0h
        pb equ 20A1h
        pc equ 20A2h
        cr equ 20A3h
data ends

code segment
start:
        mov ax,data
        mov ds,ax

        mov dx,cr
        mov al,82h      ; PA output and PB input
        out dx,al       ; Send this config to the control register

        mov cx,15h      ; 21 in decimal so we can count from 0 to 20
        mov dx,pa
        mov al,00h      ; Starting with 0

        next:
                out dx,al       ; Display the current number
                call delay
                add al,01       ; add 1 to it
                daa     ; "Decimal Adjust AL after Addition" which basically converts it to proper BCD form
                loop next

        mov cx,15h      ; Once we reach 20 in decimal, we start counting back

        next1:
                sub al,01
                das     ; "Decimal Adjust AL after Subtraction"
                out dx,al
                call delay
                loop next1
        mov ah,4ch
        int 21h

        delay proc
                mov si,06fffh
                l2:mov di,0ffffh
                l1:dec di
                jnz l1
                dec si
                jnz l2
                ret
        delay endp
code ends
end start