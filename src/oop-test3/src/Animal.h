//
// Created by cest on 5/5/21.
//
#include <string>
#include <utility>
#include "../../shared/Math/Random.h"
#include "Sex.h"
#include "AnimalType.h"

using namespace std;
#ifndef OOP_TEST3_ANIMAL_H
#define OOP_TEST3_ANIMAL_H

class Animal {
private:
    static int totalBySex[2][2];
    static void increase(Sex sex, AnimalType type) {
        Animal::totalBySex[sex][type]++;
    }
protected:
    AnimalType type;
    Sex sex;
public:
    explicit Animal(int type) {
        this->type = static_cast<AnimalType>(type);
        this->sex = static_cast<Sex>(Random::NumberBetween(FEMALE, MALE));
        Animal::increase(this->sex, this->type);
    }
    static int getFemaleTotalOf(AnimalType animalType) {
        return Animal::totalBySex[FEMALE][animalType];
    }
    static int getMaleTotalOf(AnimalType animalType) {
        return Animal::totalBySex[MALE][animalType];
    }
};


#endif //OOP_TEST3_ANIMAL_H
