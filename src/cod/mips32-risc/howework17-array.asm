.globl main	

.data
static_array: .space 160

.text
main:
  
set_static_array:
  li $t0, 2
  li $t1, 3
  li $t2, 100
  li $s0, 0              # Memory 0,4,8,...          
  sw $t0, static_array($0)   # A[0] = $t0 = 2, 0 position is $s0=0
  li $s0, 4
  sw $t1, static_array($s0)  # A[1] = $t1 = 3, 1 position is $s0=4
  li $s0, 8
  sw $t2, static_array($s0) # A[2] = $t2 = 4, 2 position is $s0=8
 	
finish: addiu $2, $0, 10
	syscall
