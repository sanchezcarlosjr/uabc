//
// Created by cest on 29/03/21.
//
#include "../OperatingSystem/OperatingSystemFactory.h"
#include <iostream>
#include <functional>
using namespace std;
#ifndef UABC_CONSOLE_H
#define UABC_CONSOLE_H

template<class T>
T print(string tag) {
    T var;
    cout << tag;
    cin >> var;
    return var;
}

template<class T>
T print(string tag, string error, function<bool(T value)> isValidInput) {
    T var;
    int reps = 0;
    do {
        if (reps > 0) {
            cout << error << endl;
        }
        cout << tag;
        cin >> var;
        reps++;
    } while (isValidInput(var));
    return var;
}

class Console {
public:
    static void pause(string message = "Press any key to continue...\n") {
        cin.clear();
        cout << endl << message;
        cin.ignore();
    }
    static void clear() {
        OperatingSystemFactory::getInstance()->getConsole()->clear();
    }
    static void pauseAndClear() {
        pause();
        clear();
    }
};

#endif //UABC_CONSOLE_H