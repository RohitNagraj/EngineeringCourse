; @Author: Piyush Mehta

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

          mov al,82h
          mov dx,cr
          out dx,al

          mov dx,pa
          mov al,00h
          out dx,al
          mov al,0f0h
          out dx,al

          mov dx,pb

    scan_agn:  in al,dx
               and al,0fh
               cmp al,0fh
               je scan_agn
               mov cl,01

     rot_agn: ror al,1
              jc next
              jmp start_mov

        next: add cl,03h
              jmp rot_agn

     start_mov:  mov dx,pa
                 mov al,0f0h

        next_led: out dx,al
                  call delay
                  inc al
                  dec cl
                 jnz next_led
                 call delay
                  call delay
                  dec al
                  and al,0fh

        come_down:  out dx,al
                    call delay
                    dec al
                    cmp al,00h
                    jge come_down

                    mov ah,4ch
                    int 21h

          delay proc
                   mov bx,02fffh
                l2: mov di,0ffffh
                l1: dec di
                    jnz l1
                    dec bx
                    jnz l2
                    ret
               delay endp
     code ends
end start