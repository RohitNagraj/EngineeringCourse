assume cs: code
code segment
start:
    mov al, 02h
    mov ah, 00h
    int 10h

    mov dx, 1240d
    mov ah, 02h
    int 10h

    mov al, 'X'
    mov bl, 8fh
    mov cx, 0001
    mov ah, 09h
    int 10h

    mov ah, 07h
    int 21h

    mov ah, 4ch
    int 21h
code ends
end start