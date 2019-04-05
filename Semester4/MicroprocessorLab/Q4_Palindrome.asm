assume cs: code, ds: data
data segment
    str1 db "madom"
    n dw n-str1
    str2 db 5 dup(?)
    msg1 db "The string is a palindrome$"
    msg2 db "The string is not a palindrome$"
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax

    lea si, n
    dec si
    lea di, str2
    mov cx, n
nextchar:
    mov al, [si]
    mov [di], al
    dec si
    inc di
    loop nextchar

compare:
    lea di, str2
    lea si, str1
    cld
    mov cx, n
    rep cmpsb
    jnz failed
    jmp success

success:
    lea dx, msg1
    jmp display
failed:
    lea dx, msg2
    jmp display

display:
    mov ah, 09h
    int 21h
    mov ah, 4ch
    int 21h
code ends
end start