/*
        Queue
        Created by Carlos Sanchez
        Created at 26/02/21
*/

#include <iostream>
#include "DataStructure/DataStructure.h"
using namespace std;

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(10);
    stack.forEach([](int element, int index) {
        cout << element << "\n";
    });
    return 0;
}
