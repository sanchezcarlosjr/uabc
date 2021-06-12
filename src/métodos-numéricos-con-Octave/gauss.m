## Copyright (C) 2021
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{retval} =} gauss (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author:  <cest@cest-desktop>
## Created: 2021-06-07
function [A,b]=gauss(A,b)
  n=length(b);
  for j = 1:n-1;
    % Eleccion fila con mayor pivote
    al = abs(A(j,j)); m=j;
    for k=j+1:n;
      if abs(A(k,j))> al
        al = abs(A(k,j)); m=k;
      end
    end
    %intercambio de filas "j" y "m"
    for l=j:n
      be=A(j,l);
      A(j,l)=A(m,l);
      A(m,l)=be;
    end
    be=b(j); b(j)=b(m); b(m)=be;
    % Cancelacion de los elementos de la
    %triangular inferior
    for k = j+1:n;
      al=-A(k,j)/A(j,j);
      for m = j:n;
        A(k,m)=A(k,m)+al*A(j,m);
      end
      b(k)=b(k)+al*b(j);
  end
end