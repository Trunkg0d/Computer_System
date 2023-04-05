%include "io.inc"
extern  _printf, _scanf, _getch

section .data
    msg1 db "Enter the first number: ", 0
    msg2 db "Enter the second number: ", 0
    msg3 db "The average is: %.2f", 10, 0
    fmtin db "%lf", 0

section .bss
    num1 resd 1
    num2 resd 1

section .text
    global CMAIN

    CMAIN:
        ; Prompt user to enter first number
        push msg1
        call printf
        add esp, 4

        ; Read in first number
        push num1
        push fmtin
        call scanf
        add esp, 8

        ; Prompt user to enter second number
        push msg2
        call printf
        add esp, 4

        ; Read in second number
        push num2
        push fmtin
        call scanf
        add esp, 8

        ; Move the first number into ST0
        fld qword[num1]

        ; Add the second number to ST0
        fadd qword[num2]

        ; Divide by 2
        fdiv qword[2]

        ; Print the result
        sub esp, 8  ; reserve space on stack for the parameter
        fstp qword[esp]  ; store the value in ST0 on the stack
        push msg3
        call printf
        add esp, 12

        ; Exit the program
        call _getch
        xor eax, eax
        ret
