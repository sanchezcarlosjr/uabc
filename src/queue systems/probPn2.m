function [prob]=probPn2(n,c,lamda, miu,rho,p0)
if n<c
    prob=(rho^n)/factorial(n)*p0;
else
    prob=(rho^n)/(factorial(c)*c^(n-c))*p0;
end

