//
// Created by cest on 27/02/21.
//

#ifndef UABC_RANDOM_H
#define UABC_RANDOM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumberBetween(int a, int b) {
    srand(time(NULL)+rand());
    return (rand()%(b-a))+a;
}

template <class T>
T generateRandomEnumBetween(int a, int b) {
    return static_cast<T>(generateRandomNumberBetween(a,b));
}


#endif //UABC_RANDOM_H
