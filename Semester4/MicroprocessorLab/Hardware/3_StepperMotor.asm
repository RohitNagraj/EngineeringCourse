; @Author: Nimish Bongale
; @Last Modified by: Rohit Nagraj

assume cs:code,ds:data
data segment
        pa equ 20a0h
        pb equ 20a1h
        pc equ 20a2h
        cr equ 20a3h
data ends

code segment
start:
        mov ax,data
        mov ds,ax

        mov dx,cr
        mov al,80h
        out dx,al

        mov cx,100d     ; This decides the angle. To rotate 90 degrees, this value should be 90/1.8 in decimal.
        mov al,11h      ; This value decides which coils of the motor are to be activted in order to perform the rotation.
        mov dx,pa

        rot:
                out dx,al
                rol al,1        ; Imagine after rotating a step, u want coils activated to also rotate in order to continue the shaft rotation.
                call delay      ; Refer this video: https://www.youtube.com/watch?v=yo2CW8qOdZE
                loop rot

        mov ah,4ch
        int 21h

        delay proc
                mov si,02fffh
                l2:mov di,0fffh
                        l1:dec di
                        jnz l1
                dec si
                jnz l2
                ret
        delay endp

code ends
end start
