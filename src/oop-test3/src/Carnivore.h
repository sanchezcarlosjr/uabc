//
// Created by cest on 5/5/21.
//
#include "Animal.h"

#ifndef OOP_TEST3_CARNIVORE_H
#define OOP_TEST3_CARNIVORE_H

class Carnivore : public Animal {
private:
    static int total;

public:
    Carnivore();
    static int getTotal();
    static Carnivore *factory();
    ~Carnivore();
};


#endif //OOP_TEST3_CARNIVORE_H
