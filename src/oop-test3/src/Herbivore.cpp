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
    this->agility = static_cast<Agility>(Random::NumberBetween(1, 3));
}

int Herbivore::getTotal() {
    return Herbivore::total;
}


Herbivore::~Herbivore() {
    Herbivore::total--;
}

string Herbivore::attack(AnimalObserver* animalObserver) {
    if (this->agility == DEFEND) {
        animalObserver->dieAnimal(this);
        return this->toString()+"==>"+"Attack event";
    }
    return this->toString();
}

string Herbivore::reproduce(AnimalObserver* animalObserver) {
    if (this->sex == FEMALE) {
        Herbivore::factory();
        return this->toString()+"==>"+"Reproduce event";
    }
    return this->toString();
}

string Herbivore::hunt(AnimalObserver* animalObserver) {
    if (this->agility == DEFEND) {
        delete this;
        animalObserver->dieAnimal(0);
        return this->toString()+"==>"+"Hunt event";
    }
    return this->toString();
}

string Herbivore::toString() {
    stringstream herbivore;
    herbivore << Animal::toString() << this->agility<< " agility";
    return herbivore.str();
}