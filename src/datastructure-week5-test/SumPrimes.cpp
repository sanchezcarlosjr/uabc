/*
        Sum Prime
        Created by Carlos Sanchez
        Created at 08/03/21
*/
#include <iostream>
using namespace std;
#include "SumPrimesAlgorithm.h"
#include "DataStructure/DataStructure.h"

int main() {
    Stack<int> stack({1,2,3,4,5,6});
    cout << sumPrimes(stack); // 10
    return 0;
}
