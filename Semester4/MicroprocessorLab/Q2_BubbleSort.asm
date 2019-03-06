; @Author: Piyush Mehta
; @Date: 2018-06-13 20:08:54 
; @Last Modified by: Rohit Nagraj
; @Last Modified time: 2019-02-21 08:45:01
assume cs:code,ds:data
data segment
        x db 5,1,2,3,4
        n dw n-x
data ends
code segment
start:
        mov ax,data
        mov ds,ax

        mov cx,n
        dec cx
next_pass:
        mov ah,0
        mov dx,cx
        lea si,x
next_cmp:
        mov al,[si]
        cmp al,[si+1]
        jle do_nothing
        mov ah,1
        xchg al,[si+1]
        mov [si],al
do_nothing:
        inc si
        dec dx
        jnz next_cmp
        cmp ah,0
        je exit1
        loop next_pass

exit1:  mov ah,4ch
        int 21h

code ends
end start