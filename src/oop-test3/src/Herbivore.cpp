//
// Created by cest on 5/5/21.
//

#include "Herbivore.h"

int Herbivore::total = 0;

Herbivore *Herbivore::factory() {
    return new Herbivore();
}

Herbivore::Herbivore(): Animal(1) {
    Herbivore::total++;
}

int Herbivore::getTotal() {
    return Herbivore::total;
}


Herbivore::~Herbivore() {
    Herbivore::total--;
}
