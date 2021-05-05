//
// Created by cest on 5/5/21.
//
#include "Animal.h"
#ifndef OOP_TEST3_CARNIVORE_H
#define OOP_TEST3_CARNIVORE_H

class Carnivore : public Animal {
private:
    static int total;
    int life;

public:
    Carnivore();
    static int getTotal();
    string attack(AnimalObserver* animalObserver) override;
    string reproduce(AnimalObserver* animalObserver) override;
    string hunt(AnimalObserver* animalObserver) override;
    string toString() override;
    static Carnivore *factory();
    ~Carnivore();
};


#endif //OOP_TEST3_CARNIVORE_H
