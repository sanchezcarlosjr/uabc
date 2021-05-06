//
// Created by cest on 5/5/21.
//

#include "Carnivore.h"

int Carnivore::total = 0;

Carnivore::Carnivore(): Animal(0) {
    Carnivore::total++;
    this->life = 3;
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

void Carnivore::attack(AnimalObserver* animalObserver) {
    this->life++;
}

void Carnivore::reproduce(AnimalObserver* animalObserver) {
    if (this->sex == FEMALE) {
        animalObserver->bornAnimal(Carnivore::factory());
    }
}

void Carnivore::hunt(AnimalObserver* animalObserver) {
    this->life--;
    if (this->life == 0) {
        animalObserver->dieAnimal();
    }
}

string Carnivore::toString() {
    stringstream animal;
    animal << Animal::toString() << this->life << " lives";
    return animal.str();
}