.globl main

.data
listsz: .word 250

.text
main:  la $t1,250
       lw $t0, ($t1)

 	
finish: addiu $2, $0, 10
	syscall
