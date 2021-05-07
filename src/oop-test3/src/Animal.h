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
    static vector<vector<vector<int>>> animalsByZone;

    static void increase(Sex sex, AnimalType type) {
        Animal::totalBySex[sex][type]++;
    }

    static void decrease(Sex sex, AnimalType type) {
        Animal::totalBySex[sex][type]--;
    }

protected:
    AnimalType type;
    Sex sex;
    int zone;
public:
    Animal(int type, int zone) {
        this->type = static_cast<AnimalType>(type);
        this->sex = static_cast<Sex>(Random::NumberBetween(FEMALE, MALE));
        this->zone = zone;
        Animal::increase(this->sex, this->type);
        this->zone < 0 || this->zone > 3 ? this->move() : this->move(this->zone);
    }

    virtual ~Animal() {
        Animal::decrease(this->sex, this->type);
        Animal::animalsByZone[this->type][this->sex][this->getZone()]--;
    };

    void update(AnimalObserver *animalObserver) {
        this->move();
        int action = Random::NumberBetween(1, 3);
        switch (action) {
            case 1:
                this->attack(animalObserver);
                break;
            case 2:
                this->reproduce(animalObserver);
                break;
            case 3:
                this->hunt(animalObserver);
                break;
        }
    }

    virtual void reproduce(AnimalObserver *animalObserver) = 0;

    virtual void attack(AnimalObserver *animalObserver) = 0;

    virtual void hunt(AnimalObserver *animalObserver) = 0;

    virtual string toString() {
        string animalType = this->type == CARNIVORE ? "Carnivore" : "Herbivore";
        string animalSex = this->sex == MALE ? "Male" : "Female";
        stringstream animal;
        animal << animalType << "," << animalSex << ",";
        return animal.str();
    }

    void move() {
        this->move(Random::NumberBetween(1,4)-1);
    }

    void move(int newZone) {
        if (this->zone != -1) {
            Animal::animalsByZone[this->type][this->sex][this->getZone()]--;
        }
        this->zone = newZone;
        Animal::animalsByZone[this->type][this->sex][this->getZone()]++;
    }

    static vector<int> byZone(AnimalType animalType, Sex sex) {
        return Animal::animalsByZone[animalType][sex];
    }

    Sex getSex() {
        return this->sex;
    }

    int getZone() {
        return this->zone;
    }

    static int getFemaleTotalOf(AnimalType animalType) {
        return Animal::totalBySex[FEMALE][animalType];
    }

    static int getMaleTotalOf(AnimalType animalType) {
        return Animal::totalBySex[MALE][animalType];
    }
};


#endif //OOP_TEST3_ANIMAL_H
