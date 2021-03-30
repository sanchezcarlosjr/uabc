//
// Created by cest on 05/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

#ifndef UABC_RANDOM_H
#define UABC_RANDOM_H

class Random {
public:
    static int Number() {
        return Random::NumberBetween(0,10);
    }
    static int NumberBetween(int a, int b) {
        srand(time(NULL) + rand());
        return (rand() % (b - a)) + a;
    }

    static bool Bool() {
        srand(time(NULL));
        return (bool) (rand() % 2);
    }

    static string String(int len=5) {
        string s;
        static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < len; ++i) {
            s += alphanum[Random::NumberBetween(1, sizeof(alphanum))];
        }
        return s;
    };
    static string Name() {
        string names[] = {
                "Adam Smith",
                "Friedrich Gauss",
                "Alan Turing",
                "Karl Marx",
                "Leonhard Euler",
                "Jonh Doe",
                "Juan Perez"
        };
        return names[Random::NumberBetween(0, 6)];
    }
};
#endif //UABC_RANDOM_H
