#include "Stack.h"
#include <gtest/gtest.h>

TEST(StackTest, addToStack){
    Stack* stack = new Stack();
    EXPECT_TRUE(stack->isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}