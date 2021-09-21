WHILE:
   bne $a0, $a1, THEN  # a != b => THEN()
   j ELSE              # a == b => ELSE()

THEN:
   add $a0, $a1, $a2 # a = b + c
   j WHILE           # WHILE()

ELSE:
    add $v0, $a0, $a1 # return a + b
    jr $ra


