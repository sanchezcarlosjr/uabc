//
// Created by cest on 5/5/21.
//
#include <string>
#include <utility>
#include <sstream>
#include "../../shared/Math/Random.h"
#include "Sex.h"
#include "AnimalType.h"
#include "AnimalObserver.h"

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
    string update(AnimalObserver* animalObserver) {
        int action = Random::NumberBetween(1,3);
        switch (action) {
            case 1:
                return this->attack(animalObserver);
            case 2:
                return this->reproduce(animalObserver);
            case 3:
                return this->hunt(animalObserver);
            default:
                return "";
        }
    }

    virtual string reproduce(AnimalObserver* animalObserver) = 0;

    virtual string attack(AnimalObserver* animalObserver) = 0;

    virtual string hunt(AnimalObserver* animalObserver) = 0;

    virtual string toString() {
        string animalType = this->type == CARNIVORE ? "Carnivore" : "Herbivore";
        string animalSex = this->sex == MALE ? "Male" : "Female";
        stringstream animal;
        animal << animalType << "," << animalSex << ",";
        return animal.str();
    }
    static int getFemaleTotalOf(AnimalType animalType) {
        return Animal::totalBySex[FEMALE][animalType];
    }
    static int getMaleTotalOf(AnimalType animalType) {
        return Animal::totalBySex[MALE][animalType];
    }
};


#endif //OOP_TEST3_ANIMAL_H
