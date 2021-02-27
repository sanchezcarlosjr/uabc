/*
        Queue
        Created by Carlos Sanchez
        Created at 26/02/21
*/

#include <iostream>
#include "DataStructure.h"
using namespace std;

int main() {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(10);
    queue.enqueue(100);
    queue.forEach([](int element, int index) {
        cout << element << "\n";
    });
    return 0;
}
