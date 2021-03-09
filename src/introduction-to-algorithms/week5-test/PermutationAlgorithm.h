//
// Created by cest on 08/03/21.
//
#include <string>
using namespace std;

#ifndef UABC_PERMUTATIONALGORITHM_H
#define UABC_PERMUTATIONALGORITHM_H

string permute(string str, int index = 0, string acc = "") {
    if (index == str.length() - 1) {
        acc += str + "\n";
        return acc;
    }
    for (int subIndex = index; subIndex < str.length(); subIndex++) {
        swap(str[index], str[subIndex]);
        acc = permute(str, index + 1, acc);
    }
    return acc;
}

#endif //UABC_PERMUTATIONALGORITHM_H
