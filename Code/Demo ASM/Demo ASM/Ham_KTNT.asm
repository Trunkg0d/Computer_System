;Viet ham tinh x mu n
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "La Nguyen To",0
    tb3 db "Khong la Nguyen To",0
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
 
    ;Goi ham _KTNT
    push dword[n]
    call _KTNT
    add esp,4
    
    ; Luu kq
    mov [kq],eax
    
    cmp dword[kq],1
    je LaNT
    ; xuat tb3
    push tb3
    call _printf
    add esp,4
    jmp KetThuc
LaNT:
    push tb2
    call _printf
    add esp,4
   
 
KetThuc:   
    call _getch
    xor eax, eax
    ret

; Viet ham Tinh Mu
;dau thu tuc
global _KTNT
_KTNT:
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
        
        mov ecx,0 ; dem = 0
        mov esi,1; i = 1
_KTNT.Lap:
        xor edx,edx
        mov eax,[ebp + 8]
        idiv esi
        
        cmp edx,0
        je _KTNT.TangDem
        jmp _KTNT.Tangi
_KTNT.TangDem:
        inc ecx
_KTNT.Tangi:        
        inc esi
        ;kiem tra i <= n thi Lap
        cmp esi, [ebp + 8]
        jle _KTNT.Lap
        ; Kiem tra dem = 2 return 1
        cmp ecx,2
        je _KTNT.Return1
        mov eax,0
        jmp _KTNT.KetThuc
_KTNT.Return1:
        mov eax,1
_KTNT.KetThuc:
;cuoi thu tuc
        ;restor thanh ghi
        pop esi
        ;xoa stack
        add esp,32
        ;phuc hoi ebp
        pop ebp
        ret