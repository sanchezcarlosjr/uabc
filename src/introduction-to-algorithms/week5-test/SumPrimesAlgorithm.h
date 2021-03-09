//
// Created by cest on 08/03/21.
//
#include "DataStructure/DataStructure.h"

#ifndef UABC_SUMPRIMESALGORITHM_H
#define UABC_SUMPRIMESALGORITHM_H

bool isPrime(int n) {
    if (n <= 3) {
        return n > 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i*i <= n) {
        int isNDivisibleByPrime = n % i == 0;
        int isNDivisibleByNextPrime = n % (i + 2) == 0;
        if (isNDivisibleByPrime || isNDivisibleByNextPrime) {
            return false;
        }
        i = i + 6;
    }
    return true;
}

int sumPrimes(Stack<int> numbers) {
    if (numbers.isEmpty()) {
        return 0;
    }
    int acc = numbers.pop();
    if (isPrime(acc)) {
        return acc + sumPrimes(numbers);
    }
    return sumPrimes(numbers);
}



#endif //UABC_SUMPRIMESALGORITHM_H
