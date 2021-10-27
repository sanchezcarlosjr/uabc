.text
MAIN:
        add $t1, $zero, $zero  # $t1=a=0
        add $t2, $zero, 100  # $t2=b=100
        add $t3, $zero, 100 # $t3=c=100
        
WHILE:
	beq $t1, $t2, EXIT # if a == b => EXIT

IF:
	bne $t1, $t2, ELSE #  if a != b => ELSE
	# If a==b
	add $t2, $t2, -1 #  b--
	j EXIT_IF
	
ELSE:
	add $t1, $t1, 1  # a++

EXIT_IF:
	sub $t2, $t1, $t3 # b=a-c
	beq $t2, 45, EXIT # if b==45 => BREAK
	add $t1, $t2, $t3 # a=b+c
	j WHILE

EXIT:
        # 10 is exit with zero status (clean exit)
        li      $v0, 10
        syscall