//
// Created by cest on 26/02/21.
//

#include "Date.h"
#include "Degree.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef UABC_STUDENT_H
#define UABC_STUDENT_H

class Student
{
private:
    string name;
    int age;
    const Date birthday;
    Date degreeDate;
    Degree degree;
public:
    Student(string, int, int, int, int, int, int, int);
    Student(string, int, int, int, int);
    Student(string, int);
    void show() const;
    ~Student();
    void setDegreeDate(int,int,int);
    void setDegreeDate(Date);
};


#endif //UABC_STUDENT_H
