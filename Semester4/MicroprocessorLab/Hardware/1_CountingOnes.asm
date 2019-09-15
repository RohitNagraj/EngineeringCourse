; @Author: Rohit Nagraj

assume cs:code, ds:data
data segment
        pa equ 20A0h
        pb equ 20A1h
        pc equ 20A2h
        cr equ 20A3h
        msg db "No of 1s : "
        ones db ?,"$"
data ends

code segment
start:
        mov ax,data
        mov ds,ax

        mov dx,cr
        mov al,82h      ; PA output and PB input
        out dx,al       ; Send this config to the control register

        mov dx,pb       ; Prepare for taking input from pb
        in al,dx        ; reading data from Port B and storing in al

        mov cx,8        ; since there are 8 bits in the interface (8 LEDs)
        mov ah,0        ; to store result 

   rot_again: 
        ror al,1        ; Rotate the binary string by 1 to the right
        jnc next        ; If there is no carry after rotating, means LSB was 0, jump to next
        inc ah          ; The LSB was 1, so after rotating, carry flag was set. Thus, inc result
    next:
        loop rot_again  ; Till cx = 0

        mov bl,ah
        add ah,30h      ; Convert to ascii
        mov ones,ah     ; Store in variable

        lea dx, msg
        mov ah, 09h     ; Print
        int 21h

        mov dx,pa
        out dx,al       ; output found in Port A

        mov ah,4ch
        int 21h
code ends
end start
