clear
clc
format rat

P=[0.5 0.5 0.0
   0.7 0.3 0.0
   0.1 0.0 0.9]



P=P';
[M,D]=eig(P);
M=M';
L=M^(-1)*D^10*M;
disp([1 0 0]*real(L))