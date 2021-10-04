.data
	 pi: .double 3.14
	 r: .double 10.0
	 
.text
MAIN:
	l.d $f2, pi
	l.d $f4, r 
	mul.d $f6, $f4, $f4 
	mul.d $f8, $f6, $f2 
	li $v0, 10
	syscall