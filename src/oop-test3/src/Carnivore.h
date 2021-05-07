//
// Created by cest on 5/5/21.
//
#include "Animal.h"
#include <iostream>
#ifndef OOP_TEST3_CARNIVORE_H
#define OOP_TEST3_CARNIVORE_H

class Carnivore : public Animal {
private:
    static int total;
    int life;

public:
    Carnivore(int);
    Carnivore();
    static int getTotal();
    void attack(AnimalObserver* animalObserver) override;
    void reproduce(AnimalObserver* animalObserver) override;
    void hunt(AnimalObserver* animalObserver) override;
    string toString() override;
    static Carnivore *factory();
    ~Carnivore() override;
};


#endif //OOP_TEST3_CARNIVORE_H
