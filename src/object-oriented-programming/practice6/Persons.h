//
// Created by cest on 12/03/21.
//
#include <string>
#include <vector>
#include "Person.h"
using namespace std;
#ifndef UABC_PERSONS_H
#define UABC_PERSONS_H

class Persons {
private:
    vector<Person*> persons;
public:
    Person* create() {
        string choose = "n";
        if (!this->persons.empty()) {
            cout << "Do you want choose an person? y/n";
            cin >> choose;
        }
        if (choose == "y") {
            cout << "CLIENTS \n";
            for (int i = 0; i < persons.size(); i++) {
                cout << i+1 << " " << persons[i]->getName() << "\n";
            }
            int id = 0;
            cout << "Which person do you want?";
            cin >> id;
            return this->persons[id-1];
        }
        this->persons.push_back(Person::create());
        return this->persons.back();
    }
};


#endif //UABC_PERSONS_H
