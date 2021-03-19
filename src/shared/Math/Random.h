//
// Created by cest on 05/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef UABC_RANDOM_H
#define UABC_RANDOM_H

class Random {
public:
    static int generateNumberBetween(int a, int b) {
        srand(time(NULL) + rand());
        return (rand() % (b - a)) + a;
    }
    static bool generateBool() {
        srand(time(NULL));
        return (bool)(rand() % 2);
    }
};

#endif //UABC_RANDOM_H
