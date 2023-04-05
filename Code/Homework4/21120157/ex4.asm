%include "io.inc"
extern _printf, _scanf, _getch

section .data
    prompt db "Nhap n: ",0
    symmetry db "So Doi Xung",0
    not_symmetry db "Khong Phai So Doi Xung",0
    format db "%d",0

section .bss
    num resd 1
    reversed_num resd 1

section .text
global CMAIN
CMAIN:
    ; Print the prompt
    push prompt
    call _printf
    add esp, 4

    ; Read in the number
    push num
    push format
    call _scanf
    add esp, 8

    ; Copy the number to reversed_num
    mov eax, [num]
    mov [reversed_num], eax

    ; Reverse the number in reversed_num
    xor ebx, ebx ; counter = 0
reverse_loop:
    mov eax, [reversed_num]
    cmp eax, 0
    je compare_num ; If reversed_num == 0, we're done
    xor edx, edx ; Clear edx
    mov eax, [reversed_num]
    mov ecx, 10
    div ecx ; Divide by 10
    mov [reversed_num], eax ; Store the quotient
    imul ebx, 10 ; Multiply counter by 10
    add ebx, edx ; Add remainder to counter
    jmp reverse_loop
compare_num:
    cmp ebx, [num] ; Compare reversed_num with num
    je is_symmetry ; If they're equal, the number is symmetric
    push not_symmetry
    call _printf ; Otherwise, print "Not symmetry"
    add esp, 4
    jmp end_program
is_symmetry:
    push symmetry
    call _printf ; Print "Symmetry"
    add esp, 4

end_program:
    call _getch
    xor eax, eax
    ret
