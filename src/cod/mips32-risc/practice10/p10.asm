.text
MAIN:
        addi $t2, $zero, 200 # t2=200
        addi $t0, $zero, 20 # t0=20
	addi $t1, $zero, 100 #t1=100
	add $s0, $zero, $t2 # a=200
	add $s1, $zero, $zero # b
	add $s2, $zero, $zero # c
	add $s3, $zero, $zero # i
	add $s4, $zero, $zero # k
	
FOR:
	bgt $s4, $t1, FINISH # k > 100 => FINISH

WHILE:
	beq $s0, $s1, FINISH_WHILE # a == b => FINISH_WHILE
	add $s2, $s0, $s4 # c=a+k
	beq $s3, $s2, FINISH_WHILE # i==c => FINISH_WHILE
	sub $s0, $s0, $t0 # a=a-20
	j WHILE

FINISH_WHILE:
	add $s1, $s4, $t0 # b=k+20
	addi $s4, $s4, 1 # k++
	j FOR  # Go to FOR
	
FINISH:
	li $v0, 10
	syscall