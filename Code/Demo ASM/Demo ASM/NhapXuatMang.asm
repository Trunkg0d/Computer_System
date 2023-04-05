; Viet chuong trinh nhap xuat mang 1 chieu n so nguyen
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "a[%d]: ",0
    tb3 db "Mang vua nhap la: ",0
    fmt1 db "%d",0
    fmt2 db "%d ",0
section .bss
    arr resd 100
    n resd 1
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
    
    call _getch
    xor eax, eax
    ret