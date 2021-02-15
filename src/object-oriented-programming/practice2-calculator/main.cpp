/*
        Practice2
        Created by Carlos Sanchez
        Created at 12/02/21
*/

#include <iostream>

using namespace std;

class Calculator {
private:
    float result = 0;
public:
    void clear() {
        this->result = 0;
    }

    void showResult() {
        cout << this->result;
    }

    void sum(float);

    void multiply(float);

    void rest(float);

    void divide(float);

    void sum(float, float);

    void multiply(float, float);

    void divide(float a, float b);

    void rest(float a, float b);

};

void Calculator::sum(float a) {
    this->sum(this->result, a);
}

void Calculator::rest(float a) {
    this->rest(this->result, a);
}

void Calculator::multiply(float a) {
    this->multiply(this->result, a);
}

void Calculator::divide(float a) {
    this->divide(this->result, a);
}

void Calculator::sum(float a, float b) {
    this->result = a + b;
}

void Calculator::rest(float a, float b) {
    this->sum(a, -b);
}

void Calculator::multiply(float a, float b) {
    this->result = a * b;
}

void Calculator::divide(float a, float b) {
    if (b == 0) {
        cout << "b cannot be 0" << "\n";
        exit(EXIT_FAILURE);
    }
    this->result = a / b;
}

int main() {
    cout << "Operation: ";
    Calculator calculator;
    float x = 0;
    float y = 0;
    char operation;
    cin >> x >> operation >> y;
    switch (operation) {
        case '+':
            calculator.sum(x, y);
            break;
        case '-':
            calculator.rest(x, y);
            break;
        case '/':
            calculator.divide(x, y);
            break;
        case '*':
            calculator.multiply(x, y);
            break;
    }
    calculator.showResult();
    do {
        cin >> operation;
        if (operation == 'S') {
            break;
        }
        if (operation == 'C') {
            calculator.clear();
        } else {
            cin >> y;
        }
        switch (operation) {
            case '+':
                calculator.sum(y);
                break;
            case '-':
                calculator.rest(y);
                break;
            case '/':
                calculator.divide(y);
                break;
            case '*':
                calculator.multiply(y);
                break;
        }
        calculator.showResult();
    } while(true);
    cout << "===Finish===";
}