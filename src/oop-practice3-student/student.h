//
// Created by cest on 17/02/21.
//
#include <string>
using namespace std;

#ifndef UABC_STUDENT_H
#define UABC_STUDENT_H


class Student {
private:
    int age;
    string name;
public:
    Student(string, int);
    string toString();
    static Student* createStudent(string name = "A", int age = 10) {
        return new Student(name, age);
    }
    ~Student();
};


#endif //UABC_STUDENT_H
