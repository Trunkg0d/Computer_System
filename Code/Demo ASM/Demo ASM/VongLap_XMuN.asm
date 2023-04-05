;Tinh tong 1 den n
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap x: ",0
    tb2 db "Nhap n: ",0
    tb3 db "%d^%d=%d",0
    fmt db "%d",0
section .bss
    x resd 1
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
    
    ;nhap x
    push x
    push fmt
    call _scanf
    add esp,8
    
     ;xuat tb2
    push tb2
    call _printf
    add esp,4
    
    ;nhap n
    push n
    push fmt
    call _scanf
    add esp,8
    
    
    ;khoi tao
    mov eax,1 ; T = 1
    mov ecx,[n] ; ecx = n
Lap:
    imul dword[x]; eax = eax*x
    LOOP Lap
    
    ; luu eax vao kq
    mov [kq],eax
    ;xuat kq
    push dword[kq]
    push dword[n]
    push dword[x]
    push tb3
    call _printf
    add esp,16
    
    call _getch
    xor eax, eax
    ret