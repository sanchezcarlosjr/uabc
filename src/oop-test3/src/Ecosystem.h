//
// Created by cest on 5/5/21.
//
#include "Herbivore.h"
#include "Carnivore.h"
#include "Animal.h"
#include "AnimalObserver.h"
#include <iostream>
#include <list>
#include "../../shared/Math/Random.h"
#include "AnimalType.h"
#include "../../shared/System/Console.h"

using namespace std;
#ifndef OOP_TEST3_ECOSYSTEM_H
#define OOP_TEST3_ECOSYSTEM_H

class Ecosystem : public AnimalObserver {
private:
    list<Animal *> animals;

    void feedback();

    void update();

    static Animal *factory();

public:
    Ecosystem();

    void *factory(int);

    void simulate(int);

    void bornAnimal(Animal *animal) override;

    void dieAnimal(int id) override;
};


#endif //OOP_TEST3_ECOSYSTEM_H
