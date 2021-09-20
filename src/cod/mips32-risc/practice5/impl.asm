if:
   beq $a0, $a1, L1
   li $v0, 1
   jr $ra

L1:
  addi $v0, $a0, 1
  jr $ra