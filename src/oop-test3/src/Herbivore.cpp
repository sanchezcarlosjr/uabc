//
// Created by cest on 5/5/21.
//

#include "Herbivore.h"

int Herbivore::total = 0;

Herbivore *Herbivore::factory() {
    return new Herbivore();
}

Herbivore::Herbivore(int zone) : Animal(HERBIVORE, zone) {
    Herbivore::total++;
    this->agility = static_cast<Agility>(Random::NumberBetween(RUN, ATTACK));
}

Herbivore::Herbivore() : Herbivore(-1) {
}

int Herbivore::getTotal() {
    return Herbivore::total;
}

Herbivore::~Herbivore() {
    Herbivore::total--;
}

void Herbivore::attack(AnimalObserver *animalObserver) {
    if (this->canDied()) {
        animalObserver->dieAnimal();
    }
}

void Herbivore::reproduce(AnimalObserver *animalObserver) {
    if (this->canReproduce()) {
        animalObserver->bornAnimal(Herbivore::factory());
    }
}

void Herbivore::hunt(AnimalObserver *animalObserver) {
    if (this->agility == ATTACK) {
        animalObserver->dieAnimal();
    }
}

void Herbivore::setAgility(Agility newAgility) {
    this->agility = newAgility;
}

string Herbivore::toString() {
    stringstream herbivore;
    herbivore << Animal::toString() << this->agility << " agility";
    return herbivore.str();
}

bool Herbivore::canDied() {
    return this->agility == ATTACK && Animal::byZone(CARNIVORE)[this->getZone()] > 0;
}
