; 7 segment display
assume cs: code, ds: data
data segment
    pa equ 20a0h
    pb equ 20a1h
    pc equ 20a2h
    cr equ 20a3h
    fire db 71h, 9fh, 0f5h, 61h
    help db 0d1h, 61h, 0e3h, 31h
data ends

code segment
start:
    mov ax, data
    mov ds, ax

    mov dx, cr
    mov al, 80h         ; Regular I/O mode
    out dx, al

    repeat:
        mov cx, 04
        lea si, fire

        display_fire:
            mov al, [si]        ; Call display on every character
            call display
            inc si
            loop display_fire

        call delay      ; Delay after displaying fire

        mov cx, 04
        lea si, help
        display_help:
            mov al,[si]
            call display
            inc si
            loop display_help
        
        mov ah, 06h     ; Check for keyboard interrupt
        mov dl, 0ffh
        int 21h
        jz repeat       ; If none, repeat
    
    mov ah, 4ch
    int 21h

    display proc
        push cx
        mov cx, 08      ; Because 8 bits per character

        nextbit:
            mov dx, pb  
            out dx, al  ; Outs one bit at a time to pb
            push ax
            mov dx, pc
            mov al, 0ffh
            out dx, al
            mov al, 00h
            out dx, al
            pop ax
            ror al, 1   ; Rotate al for the next bit
            loop nextbit
        pop cx
        ret
    display endp

    delay proc
        mov bx, 2fffh
        l1: mov di, ddffh
        l2: dec di
        jnz l2
        dec bx
        jnz l1
        ret
    delay endp
code ends
end start