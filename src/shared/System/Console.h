//
// Created by cest on 29/03/21.
//
#include <iostream>
#include <functional>
#include <string>
using namespace std;
#ifndef UABC_CONSOLE_H
#define UABC_CONSOLE_H

template<class T>
T print(string tag);

template<class T>
T print(string tag, string error, function<bool(T value)> isValidInput);

class Console {
public:
    static void pause(const string&);
    static void clear();
    static void pauseAndClear();
};

#endif //UABC_CONSOLE_H
