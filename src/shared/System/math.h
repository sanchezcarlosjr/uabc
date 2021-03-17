#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumberBetween(int a, int b) {
    srand(time(NULL)+rand());
    return (rand()%(b-a))+a;
}