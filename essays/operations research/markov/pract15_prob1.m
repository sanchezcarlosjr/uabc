# Práctica 14, problema #1

# tP=t
# P't'=t'
# P't'-t'=0
# (P'-I)t'=0
# (P-I)'t'=0
clear
clc
format rat
P=[0 1 0;2/3 0 1/3;2/3 1/3 0]
P^2
P^3
P^4
P^100
rref((P-eye(3))')
# x=8/3*z, y=3z; z=3,x=8,y=9 
t=[8 9 3]/20
