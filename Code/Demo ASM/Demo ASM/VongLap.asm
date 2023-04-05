;Tinh tong 1 den n
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "Tong 1 den %d la: %d",0
    fmt db "%d",0
section .bss
    n resd 1
    kq resd 1
section .text
global CMAIN
CMAIN:
    ;write your code here
    ;xuat tb1
    push tb1
    call _printf
    add esp,4
    
    ;nhap n
    push n
    push fmt
    call _scanf
    add esp,8
    
    ;khoi tao
    mov eax,0 ; s = 0
    mov esi,1 ; i = 1
Lap:
    add eax,esi; s + i
    inc esi ; i++
    ; kiem tra i <=n thi Lap
    cmp esi,[n]
    jle Lap
    ; luu eax vao kq
    mov [kq],eax
    ;xuat kq
    push dword[kq]
    push dword[n]
    push tb2
    call _printf
    add esp,12
    
    call _getch
    xor eax, eax
    ret