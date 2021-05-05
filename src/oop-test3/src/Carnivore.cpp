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

string Carnivore::attack(AnimalObserver* animalObserver) {
    this->life++;
    return this->toString() + "==>" + "Attack event";
}

string Carnivore::reproduce(AnimalObserver* animalObserver) {
    if (this->sex == FEMALE) {
        animalObserver->bornAnimal(Carnivore::factory());
        return this->toString() + "==>" + "Reproduce event";
    }
    return Animal::toString();
}

string Carnivore::hunt(AnimalObserver* animalObserver) {
    this->life--;
    if (this->life == 0) {
        delete this;
        animalObserver->dieAnimal(0);
        return this->toString() + "==>" + "Hunt event";
    }
    return this->toString();
}

string Carnivore::toString() {
    stringstream animal;
    animal << Animal::toString() << this->life << " lives";
    return animal.str();
}