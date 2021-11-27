% SLE_mm1_GD_N
% Nov 25/2021
% Realiza los cálculos del sistema M/M/1/GD/N/inf
% 
clc
clear
fprintf('CÁLCULO DE FÓRMULAS DEL SISTEMA M/M/1/GD/N/inf\n\n')

lambda=input('Digite el valor de lambda: ');
if isempty(lambda)
    return
end
miu=input('Digite el valor de miu: ');

% kMin=lambda/miu;
% k=0;
% while k <= kMin
%   k=input('Digite el numero de servidores: ');
% end
% kMin=ceil(lamda/miu);

N=input('Digite el valor de N (máx. de clientes en el sistema: ');
n=0;

rho=lambda/miu;

if rho==1
  Ls=N/2;
else
  Ls=rho*(1-(N+1)*rho^N+N*rho^(N+1))/((1-rho)*(1-rho^(N+1)));
end

lambdaEf=lambda*(1-probPn(N,N,lambda,miu));
Ws=Ls/lambdaEf;
Wq=Ws-1/miu;
Lq=lambdaEf*Wq;
cmedia=Ls-Lq;

fprintf('\nLamda efectiva = %4.8f:  \n',lambdaEf)
fprintf('Numero esperado de clientes Ls = %4.8f:  \n',Ls)
fprintf('Numero esperado en cola Lq = %4.8f:  \n',Lq)
fprintf('Tiempo esperado en el sistema Ws = %4.8f:  \n',Ws)
fprintf('Tiempo esperado en cola Wq = %4.8f:  \n',Wq)
fprintf('promedio de ocupación del servidor %4.8f:  \n',cmedia)

fprintf('\nn    p(n)    prob. acum.  \n')
sum=0;
for k=0:N
    prob_de_k=probPn(k,N,lambda,miu);
    sum=sum+prob_de_k;
    fprintf('%1.0f  %4.8f    %4.8f\n',k,prob_de_k,sum)
end
