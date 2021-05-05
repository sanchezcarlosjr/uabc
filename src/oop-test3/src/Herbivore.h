//
// Created by cest on 5/5/21.
//
#include "AnimalObserver.h"
#include "Animal.h"
#include <string>
#include <sstream>
#ifndef OOP_TEST3_HERBIVORE_H
#define OOP_TEST3_HERBIVORE_H

enum Agility {
    RUN = 1,
    FLY = 2,
    DEFEND = 3
};

class Herbivore: public Animal {
private:
    static int total;
    Agility agility;
public:
    Herbivore();
    static Herbivore *factory();
    static int getTotal();
    ~Herbivore();
    string toString() override;
    string attack(AnimalObserver* animalObserver) override;
    string reproduce(AnimalObserver* animalObserver) override;
    string hunt(AnimalObserver* animalObserver) override;
};


#endif //OOP_TEST3_HERBIVORE_H
