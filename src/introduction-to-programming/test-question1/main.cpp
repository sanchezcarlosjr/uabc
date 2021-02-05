/*
        1. Pedir dos números enteros diferentes y realizar lo siguiente [30 puntos]:
        Validar que los números sean diferentes (valores inválidos debe continuar solicitando).
        Guardar en la primera variable el menor y en la segunda el mayor (intercambiar valores entre las variables).
        Generar un número aleatorio en el rango de los valores dados (incluyéndolos).
        Indicar a que valor (mayor o menor) es más cercano el número aleatorio generado.
        Preguntar al usuario y permitir que pueda realizar de nuevo el proceso.
        E.j.
            Valores: 110, 5
            Menor: 5
            Mayor: 110
            Aleatorio: 43
            43 es más cercano al 5
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
        int a = print<int>("What is number A?");
        int b = print<int>("What is number B? ", "Please they should different", [a](int b) {
            return b == a;
        });
        a = a > b ? b : a;
        b = a > b ? a : b;
        int numberBetweenBAndA = generateRandomNumberBetween(a,b);
        int distanceA = abs(a - numberBetweenBAndA);
        int distanceB = abs(b - numberBetweenBAndA);
        int closestNumber =  distanceA > distanceB ? b : a;
        int longestNumber =  distanceA > distanceB ? a : b;
        //A is closer to B than C
        cout << numberBetweenBAndA << " is closer to " << closestNumber << " than " <<  longestNumber<< "\n";
        continueProgram = print<string>("Again? (y/n)");
    } while(continueProgram == "y");
    return 0;
}