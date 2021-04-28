/*
        Shared
        Created by Carlos Sanchez
        Created at 26/02/21
*/

#include "Math/Random.h"
#include "DataStructure/DataStructure.h"
#include "System/Timer.h"


int main() {
    Array* array = new Array();
    for (int i = 0; i < 100000; i++) {
        array->push(Random::Number());
    }
    time([array]() {
        array->sort();
    });
    return 0;
}
