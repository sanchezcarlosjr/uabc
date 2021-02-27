//
// Created by cest on 26/02/21.
//

#include "Degree.h"

Degree::Degree() {
    Date date(1,2,2000);
    this->degree = date;
    this->degreeType = AVERAGE;
}

Degree::Degree(Date degree, DegreeType type) {
    this->degree = degree;
    this->degreeType = type;
}

void Degree::show() const {
    this->degree.show();
    cout << "By ";
    if (this->degreeType == THESIS) {
        cout << "Thesis \n";
    }
    if (this->degreeType == PHD) {
        cout << "PhD \n";
    }
    if (this->degreeType == AVERAGE) {
        cout << "Average \n";
    }
    if (this->degreeType == EXPERIENCE) {
        cout << "Experience \n";
    }
}