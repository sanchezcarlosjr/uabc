/*
        Stack
        Created by Carlos Sanchez
        Created at 20/02/21
*/
#include "DataStructure.h"
#include "iostream"
using namespace std;
using namespace DataStructure;

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(10);
    stack.push(100);
    // 100
    cout << stack.pop() << "\n";
    // 10
    cout << stack.pop() << "\n";
    // 1
    cout << stack.pop() << "\n";
    return 0;
}
