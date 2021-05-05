#include "../src/Ecosystem.h"
#include <gtest/gtest.h>

TEST(EcosystemTest, InitState) {
    Ecosystem ecosystem;
    ecosystem.feedback();
    ASSERT_GE("", "6 carnivores, 4 females, and 2 males\n 4 herbivorous, 2 females, and 2 males.");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}