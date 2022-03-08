.model small
.stack 100

 printf macro msg
        mov dx,offset msg
        mov ah,09h
        int 21h
 endm

.data
        strp db 0ah,"Enter String:$"
        msg1 db 0ah,"The string is:$"
        str db 10 dup(?)

.code
        mov ax,@data
        mov ds,ax
        printf strp

        mov si,offset str
        loop1:mov ah,01h
        int 21h
        cmp al,0dh
        jz loop2
        mov [si],al
        inc si
        jmp loop1

        loop2:printf msg1
        mov dx,offset str
        mov ah,09h
        int 21h

        mov ah,4ch
        int 21h
end



