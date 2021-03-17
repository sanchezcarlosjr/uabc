/*
        Queue
        Created by Carlos Sanchez
        Created at 26/02/21
*/

#include <iostream>
#include "DataStructure/DataStructure.h"
#include <stdio.h>

using namespace std;

int main() {
    cout << "\n Bootstrapping... \n";
    List<char> *list = List<char>::Factory([](char c) {
        return c != '.';
    }, []() {
        return getchar();
    })->map([](int letter, int index) {
        if (letter >= 97 && letter <= 122) {
            return letter - 32;
        }
        return letter;
    });
    cout << "\n From lower case to upper case \n";
    list->forEach([](char element, int index) {
        cout << element;
    });
    cout << ".";
    return 0;
}
