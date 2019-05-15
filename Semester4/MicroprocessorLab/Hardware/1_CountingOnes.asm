; @Author: Piyush Mehta

assume cs:code, ds:data
data segment
pa equ 20A0h
Pb equ 20A1h
pc equ 20A2h
cr equ 20A3h
msg db "No of 1's : "
ones db ?,"$"
data ends

code segment
start:
        mov ax,data
        mov ds,ax

        mov dx,cr
        mov al,82h  ;PA- output and PB input
        out dx,al

        mov dx,pb
        in al,dx  ; reading data from Port B form interface

        mov cx,8          ; number of bits
        mov ah,00        ;  result 
   rot_again: ror al,01
           jnc next
           inc ah
    next: loop rot_again

          mov bl,ah
          add ah,30h
          mov ones,ah

          lea dx, msg
          mov ah, 09h
          int 21h

          mov dx,pa 
          out dx,al  ; output found in Port A

          mov ah,4ch
          int 21h

          code ends
          end start