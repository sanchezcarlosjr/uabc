//
// Created by cest on 5/5/21.
//
#include "Console.h"

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

void Console::pause(const string& message = "Press any key to continue...\n") {
    cin.clear();
    cout << endl << message;
    cin.ignore();
}

void Console::clear() {
    system("clear");
}

void Console::pauseAndClear() {
    pause();
    clear();
}
