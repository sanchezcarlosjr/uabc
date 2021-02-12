/*
        Practice2
        Created by Carlos Sanchez
        Created at 12/02/21
*/

#include <iostream>
using namespace std;

class Calculator
{
public:
    void sum(float, float);
    void multiply(float, float);
    void divide(float a, float b);
    void rest(float a, float b);
    void mod(int a, int b);
};

void Calculator::sum(float a, float b) {
    cout << a+b << "\n";
}

void Calculator::rest(float a, float b) {
    this->sum(a,-b);
}

void Calculator::mod(int a, int b) {
    cout << a%b << endl;
}

void Calculator::multiply(float a, float b) {
    cout << a*b << "\n";
}

void Calculator::divide(float a, float b) {
    if (b==0) {
        cout << "b cannot be 0" << "\n";
        exit (EXIT_FAILURE);
    }
    cout << a/b << "\n";
}

int main() {
    Calculator calculator;
    float x = 0;
    float y = 0;
    char operation;
    cin >> x >> operation >> y;
    switch(operation) {
        case '+': calculator.sum(x,y); break;
        case '-': calculator.rest(x,y); break;
        case '/': calculator.divide(x,y); break;
        case '*': calculator.multiply(x,y); break;
        case '%': calculator.mod(x,y); break;
    }
}