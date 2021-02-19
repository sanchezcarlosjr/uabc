#include "student.h"
#include <gtest/gtest.h>

TEST(Student, itShouldRemoveStudent){
    Student* student = Student::createStudent();
    delete student;
    ASSERT_TRUE(student->toString().empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}