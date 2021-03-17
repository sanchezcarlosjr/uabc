/*
        Const Student
        Created by Carlos Sanchez
        Created at 26/02/21
*/
#include "Student.h"

int main() {
    Student student("Onesimo", 10, 2, 3, 2020);
    student.show();
    student.setDegreeDate(2,5,2000);
    student.show();
    return 0;
}
