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
        cout << "Day " << i + 1 << "\n";
        this->update();
        this->feedback();
        this->feedbackByZone();
        Console::pauseAndClear();
    }
}

void Ecosystem::bornAnimal(Animal *animal) {
    this->animals.push_back(animal);
    cout << animal->toString() << " was born" << endl;
}

void Ecosystem::dieAnimal() {
    Animal *animal = (*this->actualAnimalIterator);
    cout << animal->toString() << " has died" << endl;
    this->actualAnimalIterator = this->animals.erase(this->actualAnimalIterator);
    delete animal;
}

void Ecosystem::update() {
    this->actualAnimalIterator = this->animals.begin();
    while (this->actualAnimalIterator != this->animals.end()) {
        (*this->actualAnimalIterator)->update(this);
        this->actualAnimalIterator++;
    }
}

void Ecosystem::feedbackByZone() {
    cout << "\t\t  Zone: 1 2 3 4" << endl;
    cout << "Male Carnivores\t\t" << toString<int>(Animal::byZone(CARNIVORE, MALE)) << endl;
    cout << "Female Carnivores\t" << toString<int>(Animal::byZone(CARNIVORE, FEMALE)) << endl;
    cout << "Male Herbivorous\t" << toString<int>(Animal::byZone(HERBIVORE, MALE)) << endl;
    cout << "Female Carnivores\t" << toString<int>(Animal::byZone(HERBIVORE, FEMALE)) << endl;
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

Ecosystem::~Ecosystem() {
    for (auto animal : this->animals) {
        delete animal;
    }
}

void Ecosystem::kill(AnimalType animalType, int zone) {
    auto iterator = this->animals.begin();
    while (iterator != this->animals.end()) {
        if ((*iterator)->getType() == animalType && (*iterator)->getZone() == zone) {
            Animal *animal = (*iterator);
            cout << animal->toString() << " was murdered" << endl;
            this->actualAnimalIterator = this->animals.erase(iterator);
            delete animal;
            return;
        }
        iterator++;
    }
}
