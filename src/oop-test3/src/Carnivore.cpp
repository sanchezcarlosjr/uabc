//
// Created by cest on 5/5/21.
//

#include "Carnivore.h"

int Carnivore::total = 0;

Carnivore::Carnivore(int zone): Animal(CARNIVORE, zone) {
    Carnivore::total++;
    this->life = 3;
}

Carnivore::Carnivore(): Carnivore(-1) {
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
    if (this->canFeed()) {
        this->life++;
        animalObserver->kill(HERBIVORE, this->zone);
    }
}

void Carnivore::reproduce(AnimalObserver* animalObserver) {
    if (this->canReproduce()) {
        animalObserver->bornAnimal(Carnivore::factory(this->getZone()));
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

bool Carnivore::canFeed() {
    return Animal::byZone(HERBIVORE)[this->getZone()] > 0;
}

Carnivore *Carnivore::factory(int zone) {
    return new Carnivore(zone);
}
