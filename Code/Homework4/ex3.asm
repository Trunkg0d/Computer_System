%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "La So Chinh Phuong",0
    tb3 db "Khong La So Chinh Phuong",0
    fmt db "%d",0
section .bss
    n resd 1
    kq resd 1
    temp resq 1
section .text
global CMAIN
CMAIN:
    ; Xuat tb1
    push tb1
    call _printf
    add esp,4
    
    ; Nhap n
    push n
    push fmt
    call _scanf
    add esp,8
    
    ; Goi ham Check_Square_Num
    push dword[n]
    call Check_Square_Num
    add esp,4
    
    ; Luu kq
    mov [kq],eax
    
    cmp dword[kq],1
    je LaPF
    ; xuat tb3
    push tb3
    call _printf
    add esp,4
    jmp KetThuc
LaPF:
    push tb2
    call _printf
    add esp,4
    
KetThuc:
    call _getch
    xor eax, eax
    ret
    
global Check_Square_Num
Check_Square_Num:
        ; backup ebp
        push ebp
        mov ebp,esp
        ;khai bao stack
        sub esp,32
        ;backup thanh ghi neu can
        push esi
        ;tham so 1 : n = [ebp + 8]
     
; than thu tuc
        ;khoi tao
        mov esi,1; i = 1
Check_Square_Num.Lap:
        xor edx,edx
        mov eax, esi
        imul esi
        mov [temp], eax
        jmp Check_Square
        jmp Tangi
Check_Square:
        ; Kiem tra sum = n return 1
        mov eax, [temp]
        cmp eax, [ebp + 8]
        je Check_Square_Num.Return1
        mov eax,0
Tangi:
        inc esi
        ;kiem tra i < n thi Lap
        cmp esi, [ebp + 8]
        jl Check_Square_Num.Lap
        jmp Check_Square_Num.KetThuc
Check_Square_Num.Return1:
        mov eax,1
Check_Square_Num.KetThuc:
;cuoi thu tuc
        ;restor thanh ghi
        pop esi
        ;xoa stack
        add esp,32
        ;phuc hoi ebp
        pop ebp
        ret