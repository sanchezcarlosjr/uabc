% SLE_mm1_GD_N
% Nov 25/2021
% Realiza los c�lculos del sistema M/M/1/GD/N/inf
% 
clc
clear
fprintf('C�LCULO DE F�RMULAS DEL SISTEMA M/M/1/GD/N/inf\n\n')

lambda=input('Digite el valor de lambda (cantidad de clientes nuevos en una hora [clientes/hora]): ');
if isempty(lambda)
    return
end
miu=input('Digite el valor de miu (cantidad de clientes atentidos en una hora [clientes/hora]): ');
if isempty(miu)
    return
end

% kMin=lambda/miu;
% k=0;
% while k <= kMin
%   k=input('Digite el numero de servidores: ');
% end
% kMin=ceil(lamda/miu);

N=input('Digite el valor de N (max. de clientes en el sistema): ');
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

fprintf('\nTiempo entre llegadas = %4.8f horas/cliente  \n',1/lambda);
fprintf('\nTiempo entre salidas = %4.8f horas/cliente \n',1/miu);
fprintf('\nLamda efectiva = %4.8f  \n',lambdaEf)
fprintf('Numero esperado de clientes Ls = %4.8f  \n',Ls)
fprintf('Numero esperado en cola Lq = %4.8f  \n',Lq)
fprintf('Tiempo esperado en el sistema Ws = %4.8f horas = %4.8f minutos = %4.8f segundos  \n',Ws,Ws*60,Ws*3600)
fprintf('Tiempo esperado en cola o tiempo hasta que inicie el servicio Wq = %4.8f horas = %4.8f minutos = %4.8f segundos  \n',Wq, Wq*60, Wq*3600)
fprintf('Promedio de ocupacion del servidor %4.8f  \n',cmedia)


fprintf('\nn    p(n)    prob. acum.  \n')
sum=0;
for k=0:N
    prob_de_k=probPn(k,N,lambda,miu);
    sum=sum+prob_de_k;
    fprintf('%1.0f  %4.8f    %4.8f\n',k,prob_de_k,sum)
end

fprintf('Probabilidad de que un cliente sea inmediatamente atendido p0=%4.8f  \n',probPn(0,N,lambda,miu));
fprintf('Probabilidad de que todos los espacios esten ocupados o que un cliente no encuentre lugar pN=%4.8f  \n',probPn(N,N,lambda,miu));
fprintf('Cantidad esperada de espacios vacíos (N-1)-Lq=%4.8f  \n',(N-1)-Lq);

