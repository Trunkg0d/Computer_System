; Viet chuong trinh nhap xuat mang 1 chieu n so nguyen
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "a[%d]: ",0
    tb3 db "Mang vua nhap la: ", 0
    tb4 db "Gia tri lon nhat: %d", 10, 0
    tb5 db "Tong gia tri trong mang: %d", 10, 0
    tb6 db "Gia tri trung binh cua mang: %d", 10, 0
    tb7 db "Liet ke so nguyen to: ", 0
    tb8 db " ", 10, 0
    fmt1 db "%d",0
    fmt2 db "%d ",0
    max dd 0
section .bss
    arr resd 100
    n resd 1
    sum resd 0
    float1 resq 1
    float2 resq 1
    quotient resq 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    ;xuat tb1
    push tb1
    call _printf
    add esp,4
    ;Nhap n
    push n
    push fmt1
    call _scanf
    add esp,8
    
    ;Khoi tao
    mov ebx, arr ; ebx = dia chi arr
    mov ecx,[n] ; ecx = n
    mov esi,0; i = 0
    mov eax, dword[ebx] ; Initialize max as first element of array
    mov dword[max], eax
LapNhap:
    ;xuat tb2
    push ecx; backup ecx
    push esi
    push tb2
    call _printf
    add esp,8
    
    ;nhap a[i]
    push ebx
    push fmt1
    call _scanf
    add esp,8
    
    ; Update max if necessary
    mov eax, dword[ebx]
    cmp eax, dword[max]
    jle KhongLonNhat
    mov dword[max], eax
KhongLonNhat:
    
    ; Add current element to sum
    add dword[sum], eax
    
    pop ecx; restore
    ;Tang chi so
    add ebx,4
    inc esi
    Loop LapNhap
    
    ;xuat mang
    push tb3
    call _printf
    add esp,4
    
    ;khoi tao
    mov ebx,arr
    mov esi,0
LapXuat:
    ;xuat a[i]
    push dword[ebx]
    push fmt2
    call _printf
    add esp, 8
    
    ;tang chi so
    add ebx,4
    inc esi
    ;kiem tra i < n thi lap
    cmp esi,[n]
    jl LapXuat
    
    push tb8
    call _printf
    add esp,8
    
    ;xuat ket qua
    push dword[max]
    push tb4
    call _printf
    add esp,8
    
    push dword[sum]
    push tb5
    call _printf
    add esp,8

LapTB:
    mov eax, [sum]
    mov [float1], eax
    mov eax, [n]
    mov [float2], eax
    
    fld dword[float1]      ; Load sum onto FPU stack as divisor
    fidiv dword[float2]                ; Divide dividend by divisor

    fstp dword[quotient]   ; Store the result in quotient variable

    ;xuat ket qua
    push dword[quotient]
    push tb6
    call _printf
    add esp, 12
    
KTNT:
; Dau thu tuc
    ; Back up ebp
    push ebp
    mov ebp, esp
    ; Khai bao stack
    sub esp, 32
    ; Back up thanh ghi
    push esi
    push eax
    push ebx
    push ecx
; Than thu tuc
    ; Thong bao liet ke cac so nguyen to trong mang
    push tb7
    call _printf
    add esp, 4
    ; Khoi tao vong lap
    mov ebx, arr
    mov esi, 0
KTNT.Lap:
    cmp esi, dword [n]
    jge KTNT.KetThuc
    mov ecx, 2 ; ecx = 2
    cmp dword [ebx], 2
    jl KTNT.KhongLaNguyenTo
    cmp dword [ebx], 0
    jle KTNT.KhongLaNguyenTo
    cmp dword [ebx], ecx
    jle KTNT.LaNguyenTo
KTNT.KTNT:
    mov eax, dword [ebx]
    cdq
    div ecx
    cmp edx, 0
    je KTNT.KhongLaNguyenTo 
    add ecx, 1
    cmp ecx, dword [ebx]
    jl KTNT.KTNT
KTNT.LaNguyenTo:
    push dword [ebx]
    push fmt2
    call _printf
    add esp, 8

    add ebx, 4
    inc esi
    jmp KTNT.Lap

KTNT.KhongLaNguyenTo:
    add ebx, 4 ; Tang dia chi mang len 4
    inc esi
    jmp KTNT.Lap
KTNT.KetThuc:
    pop ecx
    pop ebx
    pop eax
    pop esi
    add esp, 32
    pop ebp
     
    call _getch
    xor eax, eax
    ret
    