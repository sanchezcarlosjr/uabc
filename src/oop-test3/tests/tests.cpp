#include "../src/Ecosystem.h"
#include <gtest/gtest.h>

TEST(GenerateRandomNumberBetweenTest, positiveNumbers) {
    Ecosystem ecosystem;
    ASSERT_GE(ecosystem.show(), "");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}