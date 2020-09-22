/*
 	Cuanto cobrará en una semana un empleado del área de ventas, el cual
   	recibe el monto de su salario mas el 5% de sus ventas semanales (solicitar
   	salario semanal y ventas por día, el empleado trabaja de lunes a viernes).
        Created by Carlos Sanchez
        Created at lun 21 sep 2020 12:30:20 PDT
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
  float solds = *a[1] + *a[2] + *a[3] + *a[4] + *a[5];
  *a[0] = *a[0] + (solds * 1.05);
}
int main() {
  float salary = 0;
  float days[5] = {0, 0, 0, 0, 0};
  print("What is your salary? ", &salary,
	"Monday", &days[0],
	"Tuesday", &days[1],
	"Wednesday", &days[2],
	"Thursday", &days[3],
	"Friday", &days[4]
	);
  algorithm(&salary, &days[0], &days[1], &days[2], &days[3], &days[4]);
  print("Your salary+comision is ", salary);
  return 0;
}
