//
// Created by cest on 08/03/21.
//
// I've made an better version on
//https://colab.research.google.com/gist/sanchezcarlosjr/d03c53576beaed6d8a6ae8b4495a9f15/introduction-to-algorithms.ipynb#scrollTo=7FkKR7TNoeOQ&line=15&uniqifier=1
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
