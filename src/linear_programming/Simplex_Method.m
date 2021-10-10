% Simplex method
% Aplica el Metodo Simplex para PPL's del tipo
%         Max  Z = CX
%         s.a: AX = b
%               X >= 0
%
clc
clear
format long
fprintf('METODO SIMPLEX\n\n')

function simplex (A, M, MIN=false)
    m=size(A,1);
    n=size(A,2);
    B = A(1,:)(2:end);
    vo = length(B(B != M & B != 0));
    if MIN
      for i=2:vo+1
        A(1,i) = -A(1,i);
      endfor
    endif
    
    A
    
    for j=2:m
       C = A(j,:);
       existsANegative = length(C(C == -1)) == 1;
       if existsANegative
            A(1,:)=A(1,:)-M*C;
       end
    end

    % Determina cuantas variables basicas hay y cuales son:
    numVarBas=0;
    k=1;
    varBas=[];
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
        if MIN
          fprintf('Zmin = %8.8f \n',-A(1,n))
         else
         fprintf('Zmax = %8.8f \n',A(1,n))
        endif
        
        for j=1:vo
               fprintf('x(%1.0f) = %8.8f \n',R(j,1), R(j,2))
        end
    end
    if (solnOpt == 0) && (sinSolucion == 0) 
        fprintf('No se encontr� soluci�n �ptima en %2.0f iteraciones. \n',numIters)
    end
    if sinSolucion == 1
            fprintf('Este problema no tiene soluci�n. \n')
    end
end

M = 10^1
A=[1 -24 -22 -45 0 0 0 0
0 2 1 3 1 0 0 42
0 2 1 2 0 1 0 40
0 1 5 1 0 0 1 45
];
simplex(A,M)

