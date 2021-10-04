.data
    msg1:.asciiz "\n Dame la altura: \n"
    msg2:.asciiz "\n Dame la base: \n"
    msg3:.asciiz "\n Area: \n"
    half: .float 0.5
    
.text
main:
    # $f2=height=input_float(msg1)
    la $a0, msg1
    jal input_float
    mov.s $f2, $f0
    
    # $f4=base=input_float(msg2)
    la $a0, msg2
    jal input_float
    mov.s $f4, $f0
    
    # $f0=base=input_float(msg2)
    jal calculate_triangle_area
    
    # print_string(msg3)
    la $a0, msg3
    li	$v0, 4
    syscall
    
    # print_float(area=$f0)
    li $v0, 2
    mov.s $f12, $f0
    syscall
    
    # Exit  
    li $v0,10
    syscall

input_float:
    # print_string($a0)
    li	$v0, 4
    syscall
    
    # $f0=input()
    li	$v0, 6
    syscall

    jr $ra

calculate_triangle_area:
    l.s $f10, half # $f10=0.5
    mul.s $f0, $f4, $f2 # $f6=(height*base)
    mul.s $f0, $f0, $f10 # $f0=($f6)*0.5=(height*base)*0.5
    jr $ra