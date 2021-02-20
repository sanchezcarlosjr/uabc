#include <gtest/gtest.h>
#include "DataStructure.h"
using namespace DataStructure;

TEST(StackTest, itShouldBeEmpty){
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, itShouldNotBeEmpty){
    Stack<int> stack;
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackTest, itShouldReturnSizeOfStack){
    Stack<int> stack;
    stack.push(1);
    stack.push(1);
    stack.push(1);
    EXPECT_EQ(stack.size(), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}