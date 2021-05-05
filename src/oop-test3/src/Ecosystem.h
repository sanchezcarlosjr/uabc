//
// Created by cest on 5/5/21.
//
#include "Herbivore.h"
#include "Carnivore.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include "../../shared/Math/Random.h"
#include "AnimalType.h"
#include "../../shared/System/Console.h"

using namespace std;
#ifndef OOP_TEST3_ECOSYSTEM_H
#define OOP_TEST3_ECOSYSTEM_H

class Ecosystem {
private:
    vector<Animal*> animals;
public:
    Ecosystem();
    static Animal* factory();
    void * factory(int);
    void feedback();
};


#endif //OOP_TEST3_ECOSYSTEM_H
