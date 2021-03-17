//
// Created by cest on 26/02/21.
//

#include "Student.h"

int Student::total = 0;

Student::Student(string name, int age) {
    this->name = name;
    this->age = age;
}

Student::Student(string name,int age,int day, int month, int year): birthday(day, month, year) {
    this->name = name;
    this->age = age;
    Student::total++;
}

Student::~Student() {
    Student::total--;
}

void Student::show() const {
    cout << endl;
    cout << "Nombre:              " << name << endl;
    cout << "Edad:                " << age << endl;
    cout << "Fecha de nacimiento: ";
    birthday.show();
}