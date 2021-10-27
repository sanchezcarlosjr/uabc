clear
clc
format rat

P = [0 0.5 0.5;
     0.75 0 0.25;
     1 0 0;
     ]
 
P^10

P=P';
[M,D]=eig(P);
M=M';
L=M^(-1)*D^10000*M;
disp(real(L))