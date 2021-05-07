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
    ATTACK = 3
};

class Herbivore: public Animal {
private:
    static int total;
    Agility agility;
public:
    Herbivore(int);
    Herbivore();
    static Herbivore *factory();
    static int getTotal();
    ~Herbivore() override;
    string toString() override;
    void attack(AnimalObserver* animalObserver) override;
    void reproduce(AnimalObserver* animalObserver) override;
    bool canDied();
    void setAgility(Agility newAgility);
    void hunt(AnimalObserver* animalObserver) override;
};


#endif //OOP_TEST3_HERBIVORE_H
