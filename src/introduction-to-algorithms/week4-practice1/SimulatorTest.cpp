#include <gtest/gtest.h>
#include "Vaccines.h"

TEST(SimulatorTest, itShouldCreateAnPatient){
    Vaccines::GetInstance()->increase();
    Vaccines::GetInstance()->increase();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}