% SLE_MMcGDInfInf
% Realiza los c�lculos del sistema M/M/c/GD/inf/inf
% 
clear
fprintf('C�LCULO DE F�RMULAS DEL SISTEMA M/M/c/GD/inf/inf\n\n')

lamda=input('Digite el valor de lamda: ');
if isempty(lamda)
    return
end
miu=input('Digite el valor de miu: ');
if isempty(miu)
    return
end
c=input('Digite el n�mero de servidores c: ');

rho=lamda/miu;

sum=0;
for k=0:c-1
    sum=sum+(rho^k)/factorial(k);
end
sum=sum+(rho^c)/factorial(c)*(1/(1-rho/c));
p0=1/sum;

Lq = (rho^(c+1))/(factorial(c-1)*(c-rho)^2)*p0;
Ls = Lq + rho;
Ws = Ls/lamda;
Wq = Lq/lamda;
cmedia = Ls-Lq;
costoTot = 6*c + 12*Ws*Ls;

fprintf('\nNumero esperado de clientes Ls = %4.3f:  \n',Ls)
fprintf('Numero esperado en cola Lq = %4.3f:  \n',Lq)
fprintf('Tiempo esperado en el sistema Ws = %4.3f:  \n',Ws)
fprintf('Tiempo esperado en cola Wq = %4.3f:  \n', Wq)
fprintf('N�mero de servidores promedio desocupados: %4.3f:  \n',cmedia)
fprintf('p0 = %2.4f \n',p0)
fprintf('El costo total es de %6.2f.\n', costoTot)

fprintf('\nn    p(n)    prob. acum.  \n')
sum=0;
numEsp=6; 
N=c+numEsp;
for k=0:N
    prob_de_k=probPn2(k,c,lamda,miu,rho,p0);
    sum=sum+prob_de_k;
    fprintf('%1.0f  %4.5f    %4.5f\n',k,prob_de_k,sum)
end
