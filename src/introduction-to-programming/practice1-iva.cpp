/*
        Cuanto se pagará al comprar tres productos más el cobro del IVA. El
        porcentaje de IVA deberá solicitarlo y aplica el mismo para todos los
        productos (también solicitar el precio de cada producto).

        Created by Carlos Sanchez

        Created at lun 21 sep 2020 14:26:25 PDT
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
}
int main() {
  float x = 0;
  print("", x);
  algorithm(&x);
  print("");
  return 0;
}
