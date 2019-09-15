; Elevator
assume cs: code, ds: data
data segment
    pa equ 20a0h
    pb equ 20a1h
    pc equ 20a2h
    cr equ 20a3h
data ends

code segment
start:
    mov ax, data
    mov ds, ax

    mov dx, cr
    mov al, 82h
    out dx, al

    mov dx, pa
    mov al, 00h
    out dx, al
    
    mov al, 0f0h
    out dx, al

    mov dx, pb
    scan:
        in al, dx
        and al, 0fh
        cmp al, 0fh
        je scan

    mov cx, 1
    initialize:
        ror al,1 
        jc increment
        jmp str
    
    increment:
        add cx, 3
        jmp initialize

    str:mov dx, pa
    mov al, 0f0h
    up:
        out dx, al
        call delay
        inc al
        dec cx
        jnz up

    call delay
    call delay
    dec al
    and al, 0fh
    down:
        out dx, al
        call delay
        dec al
        cmp al, 0
        jge down
    mov ah, 4ch
    int 21h
code ends
end start


