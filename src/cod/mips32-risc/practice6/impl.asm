IF:
   move $v0, $a0
   move $v1, $a1
   bne $v0, $v1, ELSE # $v0 != $v1 => ELSE
   jal THEN           # $v0 == $v1 => THEN
   j EXIT

THEN:
   add $v0, $v0, 1
   add $v1, $v1, 1
   jr $ra

ELSE:
   add $v1, $v1, 1

EXIT:
   jr $ra