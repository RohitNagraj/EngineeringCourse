; @Author: Rohit Nagraj

assume cs:code, ds:data
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
        mov al,82h      ; PA output and PB input
        out dx,al       ; Send this config to the control register

        mov al,01       ; Initially we want the counter to be in state 1 (00000001)
    rpt:
        mov dx,pa       ; We load this every time because dl is being changed later
        out dx,al       ; Output the binary sequence 00000001 to pa

        call delay
        ror al,1        ; Rotate the sequence right, thus we get 10000000, then 01000000 and so on

        push ax         ; This block is to check for user input to break the infinite loop
        mov ah,06h      ; Checks for input from keyboard
        mov dl,0ffh
        int 21h         ; If there is an input from keyboard, zero flag is cleared. Otherwise it is set
        pop ax

        jz rpt          ; Jump if zero flag is set, ie no input from keyboard.

        mov ah,4ch
        int 21h

    delay proc
        mov si, 2fffh
    l2: mov di, 66ffh
    l1: dec di
        jnz l1          ; continues till di becomes 0
        dec si
        jnz l2          ; continues till si becomes 0
        ret
    delay endp
code ends
end start
