/*
        Queue
        Created by Carlos Sanchez
        Created at 26/02/21
*/

#include <iostream>
using namespace std;
#include "Queue.h"

int main() {
    Queue queue;
    queue.forEach([](int a) {
        cout << a << "\n";
    });
    return 0;
}
