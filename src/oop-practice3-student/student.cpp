//
// Created by cest on 17/02/21.
//

#include "student.h"

Student::Student(string name, int age) {
    this->age = age;
    this->name = name;
}

string Student::toString() {
    return name;
}

Student::~Student() {
    this->name = "";
}