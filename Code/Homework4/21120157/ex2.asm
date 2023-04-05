%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "La So Hoan Thien",0
    tb3 db "Khong La So Hoan Thien",0
    fmt db "%d",0
section .bss
    n resd 1
    kq resd 1
    sum resd 0
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
    
    ; Goi ham Check_Perfect
    push dword[n]
    call Check_Perfect
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
    
global Check_Perfect
Check_Perfect:
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
Check_Perfect.Lap:
        xor edx,edx
        mov eax,[ebp + 8]
        idiv esi
        
        cmp edx,0
        je Check_Perfect.Tangsum
        jmp Check_Perfect.Tangi
Check_Perfect.Tangsum:
        mov eax, [sum]
        add eax, esi
        mov [sum], eax
Check_Perfect.Tangi:
        inc esi
        ;kiem tra i < n thi Lap
        cmp esi, [ebp + 8]
        jl Check_Perfect.Lap
        ; Kiem tra sum = n return 1
        mov eax, [sum]
        cmp eax, [ebp + 8]
        je Check_Perfect.Return1
        mov eax,0
        jmp Check_Perfect.KetThuc
Check_Perfect.Return1:
        mov eax,1
Check_Perfect.KetThuc:
;cuoi thu tuc
        ;restor thanh ghi
        pop esi
        ;xoa stack
        add esp,32
        ;phuc hoi ebp
        pop ebp
        ret