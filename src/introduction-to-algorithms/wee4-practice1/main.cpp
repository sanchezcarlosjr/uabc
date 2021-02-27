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
    queue.forEach([](int index) {
        cout << index << "\n";
    });
    return 0;
}
