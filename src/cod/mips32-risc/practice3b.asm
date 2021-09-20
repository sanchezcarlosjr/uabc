#
#  Sum two numbers R=A+B
#
.text
	
.globl	main

main:
        jal input
        
        # Print string msg2
	li	$v0,4
	la	$a0, msg2
	syscall
        
        
	# Print string msg2
	li	$v0,4
	la	$a0, msg2
	syscall

	# Get input B from user and save
	li	$v0,5
	syscall
	move	$t1,$v0

	# A = A + B
	add	$t0, $t0, $t1

	# Print string msg3
	li	$v0, 4
	la	$a0, msg3
	syscall

	# Print sum
	li	$v0,1
	move	$a0, $t0
	syscall

	# Print \n
	li	$v0,4
	la	$a0, newline
	syscall

    # exit
	li	$v0,10
	syscall

input:
    li	$v0, 4
    la	$a0, msg1
    syscall
    
    li	$v0,5
    syscall
    move	$t0,$v0
    
    jr $ra 

.data
    msg1:	 .asciiz	"Enter A:   "
    msg2:	 .asciiz	"Enter B:   "
    msg3:	 .asciiz	"A + B = "
    newline: .asciiz	"\n"
