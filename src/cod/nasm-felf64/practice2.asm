global  sayHello

section   .data
       message:  db  "Hello, World", 10

section .text
sayHello:
        mov       rax, 1
        mov       rdi, 1
        mov       rsi, message
        mov       rdx, 13
        syscall
        ret