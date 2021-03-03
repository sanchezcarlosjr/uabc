#include <gtest/gtest.h>
#include "Student.h"

TEST(StudentTest, itShouldCalculateTotalStudents){
    Student student("Omar",2);
    Student student2("Omar",2);
    Student student3("Omar",2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}