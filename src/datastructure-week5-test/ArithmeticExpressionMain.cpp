/*
        Created by Carlos Sanchez
        Created at 09/03/21
*/
#include "ArithmeticExpression.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string expression;
    cout << "Expression: " << "\n";
    cin >> expression;
    string a = isBalancedExpression(expression) ? "It Is Balanced Expression" : "Is Not Balanced Expression";
    cout << a;
    return 0;
}
