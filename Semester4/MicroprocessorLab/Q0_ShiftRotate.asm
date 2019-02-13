; @Author: Rohit Nagraj 
; @Date: 2019-02-13 20:19:19 
; @Last Modified by:   Rohit Nagraj 
; @Last Modified time: 2019-02-13 20:19:19 

 
; Question: Shift right a number 2 times, rotate another number 3 times.

assume cs: code, ds: data

data segment
    n1 db 64h
    n2 db 50h
data ends

code segment
    start:
        mov ax, data
        mov ds, ax

        mov al, n1
        mov bl, n2

        shr al, 1 ; Shift right once
        shr al, 1

        ror bl, 1 ; Rotate right once
        ror bl, 1
        ror bl, 1

        mov n1, al ; Move the modified data back to the variables
        mov n2, bl

        mov ah, 4ch
        int 21h
code ends
end start