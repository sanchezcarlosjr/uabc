clear
clc
format rat
p=[2/3 0 1/3];
P=[0 0.5 0.5;0.5 0.5 0;0 1 0];
P^2
P^3

p*P^4
rref((P-eye(3))')

P^500