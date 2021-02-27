//
// Created by cest on 26/02/21.
//

#include "Student.h"

Student::Student(string name, int age) {
    Student(name, age);
}

Student::Student(string name,int age,int day, int month, int year): birthday(day, month, year) {
    this->name = name;
    this->age = age;
    cout << "Student was built." << endl;
}

Student::Student(string name,int age,int day, int month, int year, int degreeDay, int degreeMonth, int degreeYear):
birthday(day, month, year), degreeDate(degreeDay, degreeMonth, degreeYear) {
    this->name = name;
    this->age = age;
    cout << "Student was built." << endl;
}

Student::~Student() {
    cout << "Student was destroyed." << endl;
}

void Student::show() const {
    cout << endl;
    cout << "Nombre:              " << name << endl;
    cout << "Edad:                " << age << endl;
    cout << "Fecha de nacimiento: ";
    birthday.show();
    cout << "Fecha de titulacion: ";
    degreeDate.show();
    cout << "Titularse: ";
    degree.show();
}

void Student::setDegreeDate(Date date) {
    this->degreeDate = date;
}

void Student::setDegreeDate(int degreeDay, int degreeMonth, int degreeYear) {
    Date date(degreeDay, degreeMonth, degreeYear);
    this->setDegreeDate(date);
}