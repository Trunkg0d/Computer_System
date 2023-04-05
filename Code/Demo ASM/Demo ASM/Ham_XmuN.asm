;Viet ham tinh x mu n
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
    
    ;Goi ham _TinhMu
    push dword[n]
    push dword[x]
    call _TinhMu
    add esp,8
    
    ;Luu kq
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

; Viet ham Tinh Mu
;dau thu tuc
global _TinhMu
_TinhMu:
        ; backup ebp
        push ebp
        mov ebp,esp
        ;khai bao stack
        sub esp,32
        ;backup thanh ghi neu can
        push esi
        ;tham so 1 : x = [ebp + 8]
        ;tham so 2 : n = [ebp + 12]
; than thu tuc
        ;khoi tao
        mov eax,1 ; T = 1
        mov esi,1; i = 1
_TinhMu.Lap:
        imul dword[ebp + 8]; T = T * x
        inc esi
        ;kiem tra i <= n thi Lap
        cmp esi, [ebp + 12]
        jle _TinhMu.Lap
        
;cuoi thu tuc
        ;restor thanh ghi
        pop esi
        ;xoa stack
        add esp,32
        ;phuc hoi ebp
        pop ebp
        ret