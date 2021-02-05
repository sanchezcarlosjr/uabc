/*
      2. Generar n números aleatorios entre 1-10 considerando lo siguiente  [30 puntos]:
        Generar aleatorios hasta que el valor del último número generado sea igual al doble del número aleatorio anterior o se hayan generado 50 números aleatorios.
        Debe imprimir los números aleatorios generados e indicar cuántos números se generaron en total.
        También, debe indicar/imprimir la condicional la variante que determinó la generación de números aleatorios.
        Preguntar al usuario y permitir que pueda realizar de nuevo el proceso.
        Nota: al menos se deben generar dos números aleatorios.

        Ej.     Aleatorios: 3, 5, 4, 1, 5, 9, 3, 6

                   Se generaron 8 números aleatorios
        Created by Carlos Sanchez
        Created at 05/02/21
*/

#include <iostream>
#include <vector>
#include <functional>
#include <stdlib.h>
#include "matrix.h"
using namespace std;

int main() {
    string continueProgram;
    do {
        Matrix <int>matrix;
        matrix.__display("Numbers: \n");
        cout << matrix.size() << " generated random numbers" "\n";
        string method = (matrix.size() == 50) ? "50 elements" : "a two-fold increase";
        cout << "Program have finished by " << method << "\n";
        continueProgram = print<string>("Again? (y/n)");
    } while(continueProgram == "y");
    return 0;
}