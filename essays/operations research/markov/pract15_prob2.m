clear
clc
format rat
p=[1 0 0]
P=[0 1 0;1/6 1/2 1/3;0 2/3 1/3]
P^2
P^3
P^4
P^100
rref((P-eye(3))')
# x=1/3*z, y=2z;   z=3,x=8,y=9 
t=[1 6 3]*1/10
p*P^3