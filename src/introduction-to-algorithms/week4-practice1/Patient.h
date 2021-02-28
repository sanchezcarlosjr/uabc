//
// Created by cest on 27/02/21.
//

#include "System/Random.h"
#include <iostream>
using namespace std;
#ifndef UABC_PATIENT_H
#define UABC_PATIENT_H

enum Money {
    LOW = 0,
    MIDDLE = 1,
    HIGH = 2
};

enum Age {
    CHILD = 0,
    ADULT = 1,
    ELDERLY = 2
};

enum Power {
    CITIZEN = 0,
    LOCAL_GOVERNMENT = 1,
    STATE_GOVERNMENT = 2,
    FEDERAL_GOVERNMENT = 3
};

enum Priority {
    URGENT_IMPORTANT = 0,
    NO_URGENT_IMPORTANT = 1,
    URGENT_NO_IMPORTANT = 2,
    NO_URGENT_NO_IMPORTANT = 3
};

class Patient {
private:
    Money money;
    Age age;
    Power power;
public:
    Patient(Age age, Money money, Power power) {
        this->money = money;
        this->age = age;
        this->power = power;
    }
    Patient() {
        this->money = generateRandomEnumBetween<Money>(Money::LOW,Money::HIGH);
        this->age = generateRandomEnumBetween<Age>(Age::CHILD, Age::ELDERLY);
        this->power = generateRandomEnumBetween<Power>(Power::CITIZEN,Power::FEDERAL_GOVERNMENT);
    }
    void talk() {
        cout << "Hi " << money << age << power << this->getPriority() <<"\n";
    }
    int getPriority() {
        if (
                age == ELDERLY &&
                money == HIGH &&
                power >= FEDERAL_GOVERNMENT) {
            return URGENT_IMPORTANT;
        }
        if (
                age <= ELDERLY &&
                money == HIGH &&
                power < FEDERAL_GOVERNMENT
                ) {
            return NO_URGENT_IMPORTANT;
        }
        if (
                age == ELDERLY &&
                money < HIGH &&
                power < FEDERAL_GOVERNMENT
                ) {
            return URGENT_NO_IMPORTANT;
        }
        return NO_URGENT_NO_IMPORTANT;
    }
};


#endif //UABC_PATIENT_H
