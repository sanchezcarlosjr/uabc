#include <iostream>
#include <functional>
using namespace std;

template<class T>
T print(string tag) {
    T var;
    cout << tag;
,    return var;
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
        cin>>var;
        reps++;
    }while(isValidInput(var));
    return var;
}