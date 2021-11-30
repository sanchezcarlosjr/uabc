function [prob]=probPn(n,N,lambda, miu)
rho=lambda/miu;
if rho==1
  prob=1/(N+1);
else
  prob=(1-rho)*rho^n/(1-rho^(N+1));
end



