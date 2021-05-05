//
// Created by cest on 5/5/21.
//

#include "Carnivore.h"

int Carnivore::total = 0;

Carnivore::Carnivore(): Animal(0) {
    Carnivore::total++;
}

Carnivore * Carnivore::factory() {
    return new Carnivore();
}

Carnivore::~Carnivore() {
    Carnivore::total--;
}

int Carnivore::getTotal() {
    return Carnivore::total;
}
