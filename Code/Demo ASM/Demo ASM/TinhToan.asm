;Nhap 2 so a,b. Tinh tong, hieu, tich, thuong, a.b

%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap a: ",0
    tb2 db "Nhap b: ",0
    tb3 db "%d %c %d = %d",10,0
    fmt db "%d",0
    
section .bss
    numa resd 1
    numb resd 1
    kq resd 1
    
section .text
global CMAIN
CMAIN:
    ;write your code here
    ;xuat tb1
    push tb1
    call _printf
    add esp,4
    
    ;nhap a
    push numa
    push fmt
    call _scanf
    add esp,8
    
    ;xuat tb2
    push tb2
    call _printf
    add esp,4
    
    ;nhap b
    push numb
    push fmt
    call _scanf
    add esp,8
    
    ;Tinh tong
    mov eax,[numa]
    add eax,[numb]
    mov [kq],eax
    
    push dword[kq]
    push dword [numb]
    push dword '+'
    push dword [numa]
    push tb3
    call _printf
    add esp,20
    
    
    ;Tinh hieu
    mov eax,[numa]
    sub eax,[numb]
    mov [kq],eax
    
    push dword[kq]
    push dword [numb]
    push dword '-'
    push dword [numa]
    push tb3
    call _printf
    add esp,20
    
    
    ;Tinh tich
    mov eax,[numa]
    imul dword[numb]
    mov [kq],eax
    
    push dword[kq]
    push dword [numb]
    push dword '*'
    push dword [numa]
    push tb3
    call _printf
    add esp,20
    
    ;Tinh thuong 
    mov eax,[numa]
    idiv dword[numb]
    mov [kq],eax
    
    push dword[kq]
    push dword [numb]
    push dword '/'
    push dword [numa]
    push tb3
    call _printf
    add esp,20
    
    call _getch
    xor eax, eax
    ret