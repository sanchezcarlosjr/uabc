#
#  Sum three numbers R=A+B+C
#
.text
	
.globl	main

main:
    la $a1, msgA
    jal input
    move $t0,$v0
    
    la $a1, msgB
    jal input
    add $t0, $t0, $v0
    
    la $a1, msgC
    jal input
    add $t0, $t0, $v0
     
    la $a1, msgTotal
    jal print_string
    
    move $a1, $t0
    jal print_int
    
    la $a1, newline
    jal print_string

    # exit
    li	$v0,10
    syscall

input:
    li	$v0, 4
    move $a0, $a1
    syscall
    
    li	$v0,5
    syscall
    
    jr $ra
    
print_string:
    li	$v0, 4
    move $a0, $a1
    syscall
    
    jr $ra
    
print_int:
    li	$v0, 1
    move $a0, $a1
    syscall
    
    jr $ra  
  

.data
    msgA:	 .asciiz	"Enter A:   "
    msgB:	 .asciiz	"Enter B:   "
    msgC:	 .asciiz	"Enter C:   "
    msgTotal:	 .asciiz	"A + B + C = "
    newline: .asciiz	"\n"
