//
// Created by cest on 5/5/21.
//

#include "AnimalType.h"

class Animal;
#ifndef OOP_TEST3_ANIMALOBSERVER_H
#define OOP_TEST3_ANIMALOBSERVER_H

class AnimalObserver {
public:
    virtual void kill(AnimalType animalType, int zone) = 0;
    virtual void bornAnimal(Animal* animal)  = 0;
    virtual void dieAnimal() = 0;
};


#endif //OOP_TEST3_ANIMALOBSERVER_H
