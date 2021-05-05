//
// Created by cest on 5/5/21.
//

#include "Ecosystem.h"

void Ecosystem::feedback() {
    cout << Carnivore::getTotal() << " carnivores, " << Animal::getFemaleTotalOf(CARNIVORE) << " females, and "
         << Animal::getMaleTotalOf(CARNIVORE) << " males.\n";
    cout << Herbivore::getTotal() << " herbivorous, " << Animal::getFemaleTotalOf(HERBIVORE) << " females, and "
         << Animal::getMaleTotalOf(HERBIVORE) << " males.\n";
}

Ecosystem::Ecosystem() {
    this->factory(10);
    cout << "Initial population\n";
    this->feedback();
    Console::pauseAndClear();
}

Animal *Ecosystem::factory() {
    int randomNumber = Random::NumberBetween(1, 2);
    switch (randomNumber) {
        case 1:
            return Carnivore::factory();
        case 2:
            return Herbivore::factory();
        default:
            return nullptr;
    }
}

void *Ecosystem::factory(int size) {
    for (int i = 0; i < size; i++) {
        this->animals.push_back(Ecosystem::factory());
    }
    return nullptr;
}
