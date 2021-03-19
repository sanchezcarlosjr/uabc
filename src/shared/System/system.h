//
// Created by cest on 17/03/21.
//
#include <iostream>
#include <functional>
using namespace std;

#ifndef UABC_SYSTEM_H
#define UABC_SYSTEM_H

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
        // TODO: Linux, Windows and Apple
        system("clear");
    }
};

#endif //UABC_SYSTEM_H
