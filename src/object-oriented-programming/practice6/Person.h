//
// Created by cest on 05/03/21.
//

#include <string>
#include <iostream>
using namespace std;
#ifndef UABC_PERSON_H
#define UABC_PERSON_H

class Person {
private:
    string name;
    string phone;
public:
    Person(string name, string phone) {
        this->setName(name);
        this->setPhone(phone);
    }
    static Person* create() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string name;
        cout << "Person's name: ";
        getline (cin,name);
        string phone;
        cout << "Phone's number: ";
        getline (cin,phone);
        return new Person(name, phone);
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }
    string getPhone() {
        return this->phone;
    }
};


#endif //UABC_PERSON_H
