%include "io.inc"
extern _getch
section .data
    str1 db "Hello world",0    
section .text
global CMAIN
CMAIN:
    ;write your code here
    ;printf("Hello world");
    push str1
    call _printf
    add esp,4
    
    call _getch
    
    xor eax, eax
    ret