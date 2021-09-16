% MS_alumnos
% Aplica el M�todo Simplex para PPL's del tipo
%         M�x  Z = CX
%         s.a: AX = b
%               X >= 0
%
clc
clear
fprintf('M�TODO SIMPLEX\n\n')

%Pract de Lab #7
A=[1 -5 -3 0 0 0 0;0 3 -1 1 0 0 5;0 2 3 0 1 0 18;0 1 1 0 0  1 20];
vo=2; % (N�mero de variables originales del problema)

% Pract de Lab #6
% A=[1 -3 -2 0 0 0 0 0;0 2 4 1 0 0 0 26;0 -1 4 0 1 0 0 12;...
%    0 2 -1 0 0 1 0 6; 0 1 -3 0 0 0 1 2];
% vo=2;  % (N�mero de variables originales del problema)

% Pract de Lab #3 (compa��a de seguros, Riesgo Especial)
% A=[1 -5 -2 0 0 0 0;0 3 2 1 0 0 2400;0 0 1 0 1 0 800;0 2 0 0 0 1 1200];
% vo=2; % (N�mero de variables originales del problema)

% Problema 1a de Pract #8
% A=[1 -2 -1 0 0 0 0 0;0 0 -1 1 0 0 0 10;0 2 5 0 1 0 0 60;...
%      0 1 1 0 0 1 0 18;0 2 1 0 0 0 1 44];
% vo=2; % (N�mero de variables originales del problema)

% Problema 1b de Pract #8
%  A=[1 -3 -5 -6 0 0 0 0 0;0 1 1 1 1 0 0 0 14;0 1 2 1 0 1 0 0 4;...
%     0 5 -3 7 0 0 1 0 23;0 3 4 2 0 0 0 1 17];
%  vo=3; % (N�mero de variables originales del problema)

% Problema 1c de Pract #8
 % A=[1 -5 -1 -3 -4 0 0 0 0;0 1 -2 4 3 1 0 0 20;0 -4 6 5 -4 0 1 0 20;...
 %    0 2 -3 3 8 0 0 1 50];
 % vo=3; % (N�mero de variables originales del problema)

% Prob 3, pract. 8: Agricultor,acres, ma�z, trigo, etc.
% A=[1 -30 -100 0 10^3 0 0 0;0 1 0 -1 1 0 0 3;0 1 1 0 0 1 0 7;0 2 5 0 0 0 1 20];
% A(1,:)=A(1,:)-A(1,5)*A(2,:); %(Para obtener forma apropiada)
% vo=2; % (N�mero de variables originales del problema)

%Pract Lab #9, prob #1
%A=[1 5 7 0 10^1 0 10^1 0;0 2 1 -1 1 0 0 3;0 1 3 0 0 -1 1 7];
%A(1,:)=A(1,:)-A(1,5)*A(2,:); %(Para obtener forma apropiada)
%A(1,:)=A(1,:)-A(1,7)*A(3,:);
%vo=2; % (N�mero de variables originales del problema)

% Pract #9, prob #2
% A=[1 -4 -2 -3 -5 10^1 10^1 0;0 2 3 4 2 1 0 300;...
%    0 8 1 1 5 0 1 300];
% A(1,:)=A(1,:)-A(1,6)*A(2,:); %(Para obtener forma apropiada)
% A(1,:)=A(1,:)-A(1,7)*lA(3,:);
% vo=4; % (N�mero de variables originales del problema)


% Pract #9, prob #3
% A=[1 3 2 0 10^2 0 10^2 0;0 1 1 1 0 0 0 12;...
%   0 2 3 0 1 0 0 12; 0 2 1 0 0 -1 1 8];
% A(1,:)=A(1,:)-A(1,5)*A(3,:);
% A(1,:)=A(1,:)-A(1,7)*A(4,:);
% vo=2; 
 
% Pract #9, prob 4
% A=[1 60 50 0 10^3 0 10^3 0 10^3 0
%      0 5 3 -1 1 0 0 0 0 60
%      0 2 2 0 0 -1 1 0 0 30
%        0 7 9 0 0 0 0 -1 1 150]
% A(1,:)=A(1,:)-A(1,5)*A(2,:);
% A(1,:)=A(1,:)-A(1,7)*A(3,:);
% A(1,:)=A(1,:)-A(1,9)*A(4,:);
% vo=2; 

% Pract #9, prob 5
%A=[1 84 72 60 0 10^3 0 10^3 0 10^3 0
%0 90 20 40 -1  1 0 0 0  0 200
%0 30 80 60 0 0 -1 1 0 0 180
%0 10 20 60 0 0 0 0 -1 1 150]
% A(1,:)=A(1,:)-A(1,6)*A(2,:);
% A(1,:)=A(1,:)-A(1,8)*A(3,:);
% A(1,:)=A(1,:)-A(1,10)*A(4,:);
% vo=3; 

% Pract #9, prob 6
A=[1 0.4 0.5 0 10^2 0 10^2 0
     0 0.3 0.1 1 0 0 0 2.7
0 0.5 0.5 0 1 0 0 6
0 0.6 0.4 0 0 -1 1 6]
 A(1,:)=A(1,:)-A(1,5)*A(3,:);
 A(1,:)=A(1,:)-A(1,7)*A(4,:);
 vo=2; 


m=size(A,1);
n=size(A,2);
numVarBas=0;

% Determina cu�ntas variables b�sicas hay y cu�les son:
k=1;
varBas='';
for j=2:n-1
    if A(1,j) == 0
        varBas(k)=j-1;
        k=k+1;
        numVarBas = numVarBas + 1;
    end
end
%%%%

% Si solnOpt=1 se encontr� la soluci�n �ptima
% Si sinSolucion=1 el problema no tiene soluci�n

numMaxIters=10;
solnOpt=0;
sinSolucion=0;

for numIters=1:numMaxIters

    % Despliega tabla;
    if numIters == 1  
      fprintf('V.BAS          Z ')
      for j=1:n-2
        fprintf('         X%1.0f ',j)
      end
      fprintf('          b\n')
    end
    fprintf('  Z   ')
    fprintf(' %11.2f',A(1,:))
    fprintf('\n')
    for i=2:m
        fprintf('  X%1.0f  ',varBas(i-1))
        fprintf(' %11.2f',A(i,:))
        fprintf('\n')
    end
    resp=input('==>','s');
    fprintf('\n')
    % soluci�n opt? Si no, qui�n es la VNBE:
    masNeg=0;
    for j=2:n-1
        if A(1,j) < masNeg
            masNeg = A(1,j);
            cp=j;
        end
    end
    
    % Qui�n es la VBS o si no hay soluci�n:
    if masNeg < 0
        cocientMin=10^10;
        for i=2:m
            if A(i,cp)>0
                cociente=A(i,n)/A(i,cp);
                if cociente < cocientMin
                    cocientMin = cociente;
                    rp=i;
                end
            end
        end
        if cocientMin==10^10
            sinSolucion=1;
            break
        end
        
        % Actualiza vector de soluciones b�sicas:
        varBas(rp-1)=cp-1;
        
        % Aplica Gauss Jordan:
        rengPiv = A(rp,:)/ A(rp,cp);
        A(rp,:) = rengPiv ;
        for i=1:m
            if i ~= rp
                A(i,:) = A(i,:) - A(i,cp)*rengPiv;
            end
        end
 
    else
        solnOpt = 1;
        break
    end
    
end 

if (solnOpt == 1) && (sinSolucion == 0) 
    
    % Ordena de menor a mayor las soluciones b�sicas:
    R=0;
    for i=1:vo
        R(i,1)=i;
        R(i,2)=0;
        for j=1:numVarBas
            if varBas(j)==i
                R(i,2)=A(j+1,n);
            end
        end
    end
    
%     A
    fprintf('Zm�x = %8.4f \n',A(1,n))
    for j=1:vo
           fprintf('x(%1.0f) = %8.4f \n',R(j,1), R(j,2))
    end
end
if (solnOpt == 0) && (sinSolucion == 0) 
    fprintf('No se encontr� soluci�n �ptima en %2.0f iteraciones. \n',numIters)
end
if sinSolucion == 1
        fprintf('Este problema no tiene soluci�n. \n')
end
