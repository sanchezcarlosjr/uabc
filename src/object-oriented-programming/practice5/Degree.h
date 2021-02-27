//
// Created by cest on 26/02/21.
//
#include <string>
#include "Date.h"
using namespace std;
#ifndef UABC_DEGREE_H
#define UABC_DEGREE_H

enum DegreeType {
    THESIS = 0,
    AVERAGE = 1,
    EXPERIENCE = 2,
    PHD = 3
};

class Degree {
private:
    DegreeType degreeType;
    Date degree;
    string converter(DegreeType);
public:
    Degree();
    Degree(Date, DegreeType type);
    void show() const;
};


#endif //UABC_DEGREE_H
