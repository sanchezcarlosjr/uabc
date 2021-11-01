clear
clc
format rat

P=[0.9 0.1 0 0; 
   0.6 0.4 0 0; 
   0 0 0.5 0.5; 
   0 0 0.3 0.7]
 

P=P';
[M,D]=eig(P);
M=M';
L=M^(-1)*D^1000*M;
disp(real(L))
