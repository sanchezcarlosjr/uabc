#include "math.h"
#include <gtest/gtest.h>

TEST(GenerateRandomNumberBetweenTest, positiveNumbers){
ASSERT_GE(generateRandomNumberBetween(11,100), 11);
ASSERT_LE(generateRandomNumberBetween(11,100), 100);
ASSERT_NE(generateRandomNumberBetween(11,100), generateRandomNumberBetween(11,100));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}