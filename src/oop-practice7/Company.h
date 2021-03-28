//
// Created by cest on 26/03/21.
//
#include <string>

using namespace std;
#ifndef UABC_COMPANY_H
#define UABC_COMPANY_H

class Company {
protected:
    static int amountOfCompanies;
    string name;
    Company() {
        Company::increase();
    }
    Company(string name) {
        this->name = name;
        Company::increase();
    }
    void static increase() {
        Company::amountOfCompanies++;
    }
public:
    int getAmountOfCompanies() {
        return Company::amountOfCompanies;
    }
};

int Company::amountOfCompanies = 0;

#endif //UABC_COMPANY_H
