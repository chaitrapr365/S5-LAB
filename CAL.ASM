.model small
.stack 64
displaystr macro msg
        mov dx,offset msg
        mov ah,09h
        int 21h
endm

displayno macro num
        mov dl,al
        mov ah,02h
        int 21h
endm

readno macro num
        mov ah,01h
        int 21h
        sub al,30h
        mov num,al
endm


.data
        msg1 db 0ah,"CALCULATOR 1.Add 2.Sub 3.Mul 4.Div 5.Exit$"
        msg2 db 0ah,"Enter choice:$"
        msg3 db 0ah,"Enter no 1:$"
        msg4 db 0ah,"Enter no 2:$"
        resst db 0ah,"Result=$"
        addst db 0ah,"ADDITION$"
        subst db 0ah,"SUBTRACTION$"
        mulst db 0ah,"MULTIPLICATION$"
        divst db 0ah,"DIVISION$"
        num1 db ?
        num2 db ?
        ch1 db ?
.code
        start:mov ax,@data
        mov ds,ax
        displaystr msg1
        displaystr msg2
        readno ch1
        cmp ch1,05
        jz exit
        displaystr msg3
        readno num1
        displaystr msg4
        readno num2
        cmp ch1,01h
        jz addnos
        cmp ch1,02h
        jz subnos
        cmp ch1,03h
        jz mulnos
        cmp ch1,04
        jz divnos

        exit:mov ah,4ch         
        int 21h

        addnos:displaystr addst
        mov al,num1
        add al,num2
        add al,30h
        displaystr resst
        displayno al
        jmp start

        subnos:displaystr subst
        mov al,num1
        sub al,num2
        add al,30h
        displaystr resst
        displayno al
        jmp start

        mulnos:displaystr mulst
        mov al,num1
        mul num2
        add al,30h
        displaystr resst
        displayno al
        jmp start

        divnos:mov ah,00
        mov al,num1
        div num2
        add al,30h
        displaystr resst
        displayno al
        jmp start
end



