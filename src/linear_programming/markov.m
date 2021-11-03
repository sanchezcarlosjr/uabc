clear
clc


P=[0.2 0.5 0.3; 
   0.0 0.5 0.5; 
   0.0 0.0 1; 
   ]

P^10

P=P';
[M,D]=eig(P);
M=M';
L=M^(-1)*D^1*M;
disp(real(L))
