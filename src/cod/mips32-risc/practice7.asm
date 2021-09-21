.text
	li $s1, 3
	li $s2, 2
    li $s3, 1
    li $s4, 1

	bne $s3,$s4,Else
	add $s0,$s1,$s2 # $s0 = $s1 + $s2
	j Exit

# $s0 = $s1 - $s2
Else: sub $s0,$s1,$s2

Exit:   li      $v0, 10                 # 10 is exit with zero status (clean exit)
        syscall