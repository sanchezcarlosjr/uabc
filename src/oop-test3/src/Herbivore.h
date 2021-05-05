//
// Created by cest on 5/5/21.
//
#include "Animal.h"
#ifndef OOP_TEST3_HERBIVORE_H
#define OOP_TEST3_HERBIVORE_H

class Herbivore: public Animal {
private:
    static int total;
public:
    Herbivore();
    static Herbivore *factory();
    static int getTotal();
    ~Herbivore();
};


#endif //OOP_TEST3_HERBIVORE_H
