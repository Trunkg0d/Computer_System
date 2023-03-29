%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap a: ",0
    tb2 db... "Nhap b: ",0
    tb3 db "%d %c %d = %d",0
    fmt db "%d",0  
section .bss
    a resd 1
    b resd 1
    c resd 1 
section .text
global CMAIN
CMAIN:
    ;write your code here
    ;xuat tb1
    push tb1
    call _printf
    add esp,4
    
    ;nhap a
    ;scanf("%d",&a);
    push a
    push fmt
    call _scanf
    add esp,8
    
     ;xuat tb2
    push tb2
    call _printf
    add esp,4
    
    ;nhap b
    ;scanf("%d",&b);
    push b
    push fmt
    call _scanf
    add esp,8
    
    ;Tinh tong
    mov eax,[a]
    add eax,[b]
    
    ;luu tong
    mov [c],eax
    ; xuat kq
    
    push dword[c]
    push dword[b]
    push dword '+'
    push dword[a]
    push tb3
    call _printf
    add esp,20
    
    call _getch
    
    xor eax, eax
    ret