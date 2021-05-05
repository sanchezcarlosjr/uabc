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

void Ecosystem::simulate(int days) {
    for (int i = 0; i < days; i++) {
        cout << "Day "<< i+1 << "\n";
        this->update();
        this->feedback();
        Console::pauseAndClear();
    }
}

void Ecosystem::bornAnimal(Animal *animal) {
    this->animals.push_back(animal);
}

void Ecosystem::dieAnimal(int id) {
    cout << "\n" << "Die" << "\n";
}

void Ecosystem::update() {
    for (auto animal : this->animals) {
        cout << animal->update(this) << "\n";
    }
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
