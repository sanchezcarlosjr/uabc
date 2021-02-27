//
// Created by cest on 26/02/21.
//

#include <iostream>
#include <string>

using namespace std;

#ifndef UABC_DATE_H
#define UABC_DATE_H

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() {
       Date(0,0,0);
    }
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        cout << "Date was built." << endl;
    }

    void show() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    ~Date() {
        cout << "Date was destroyed." << endl;

    }
};

#endif //UABC_DATE_H
