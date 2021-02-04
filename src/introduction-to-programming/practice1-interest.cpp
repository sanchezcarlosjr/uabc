/*
        Cuanto dinero se recibira despues de un mes, si se invierte cierta
   	cantidad y se otorga un 2% de interes mensual 
	Created by Carlos Sanchez
        Created at lun 21 sep 2020 12:10:05 PDT
*/

#include <boost/any.hpp>
#include <cstdarg>
#include <iostream>
#include <stdlib.h>
#include <vector>
using boost::any_cast;
using namespace std;

template <typename T, typename... Types> void print(T var1, Types... var2) {
  vector<boost::any> a({var1, var2...});
  for (int i = 0; i < a.size(); i++) {
    if (a[i].type() == typeid(int)) {
      cout << boost::any_cast<int>(a[i]);
    }
    if (a[i].type() == typeid(float *)) {
      scanf("%f", boost::any_cast<float *>(a[i]));
    }
    if (a[i].type() == typeid(int *)) {
      scanf("%i", boost::any_cast<int *>(a[i]));
    }
    if (a[i].type() == typeid(float)) {
      cout << boost::any_cast<float>(a[i]);
    }
    if (a[i].type() == typeid(const char *)) {
      cout << boost::any_cast<const char *>(a[i]) << " ";
    }
  }
}
template <typename T, typename... Types> void algorithm(T var1, Types... var2) {
  vector<float *> a({var1, var2...});
  *a[0] = *a[0] * 1.02;
}
int main() {
  float budget = 0.0;
  print("How much initial budget? ", &budget);
  algorithm(&budget);
  print("After month, your money is",budget);
  return 0;
}
