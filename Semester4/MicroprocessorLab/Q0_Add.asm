; @Author: Rohit Nagraj 
; @Date: 2019-02-13 20:19:31 
; @Last Modified by:   Rohit Nagraj 
; @Last Modified time: 2019-02-13 20:19:31 

 
assume cs:code, ds:data 
; Tells the assembler to assume that the code segment register(CS) points to a
; segment named code and the data segment register(ds) points to a segment named data

data segment ; The ds register points to this segment

    num1 db 23h ; Defines a variable named num1 of type databyte and value 23hex
    num2 db 22h

    sum db ? ; The ? represents empty/unknown value
data ends ; The data segment ends here

code segment ; The cs register points to this segment
start: ; This is the entry point of the program

    mov ax,data ; Moves the address of data (segment in line 5) to ax
    mov ds,ax ; Moves the address of ax to data segment register (ds)

; Why not directly mov ds,data? Because ds is a segment register and only 
; general purpose registers (ax,bx,cx,dx) can give values to segment registers


    mov al,num1 ; Moves the value of num1 to al (ie the last 2 nibbles of ax)
    mov bl,num2

    add al,bl ; Adds value in al and bl and stores it in al
    mov sum,al ; Moves the value of al to sum

    mov ah, 4ch
    int 21h ; Exit: Terminate with content of al as the return code, ie it 
; terminates with the sum being returned
code ends ; code segment ends here
end start ; The program execution will end here if the exit interrupt wasn't
; given
