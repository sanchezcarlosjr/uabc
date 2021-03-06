//
// Created by cest on 19/03/21.
//
#include <string>
#include <sstream>
#include "../Math/Random.h"
using namespace std;
#ifndef UABC_PATIENT_H
#define UABC_PATIENT_H


class Patient {
private:
    string gender;
    int age;
    int days;
public:
    Patient() {
        this->gender = Random::generateBool() ? "Woman" : "Man";
        this->age = Random::generateNumberBetween(1,100);
        this->days = 0;
    }
    string toString() {
        stringstream patient;
        patient << this->gender << "-" << this->age << "-" << this->days;
        this->days++;
        return patient.str();
    }
    bool canExit() {
        return  Random::generateNumberBetween(1,4) == 2;
    }
};


#endif //UABC_PATIENT_H
