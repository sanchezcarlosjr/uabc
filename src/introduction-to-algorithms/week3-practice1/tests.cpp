#include <gtest/gtest.h>
#include "DataStructure.h"
using namespace DataStructure;

TEST(StackTest, itShouldBeEmpty){
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}