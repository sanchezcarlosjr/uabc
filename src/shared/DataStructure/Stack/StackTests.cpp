#include <gtest/gtest.h>
#include <iostream>
#include "../DataStructure.h"
using namespace std;

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

TEST(StackTest, itShouldPopElementsOfAStackWith3Elements){
    Stack<int> stack;
    stack.push(1);
    stack.push(10);
    stack.push(100);
    EXPECT_EQ(stack.size(), 3);
    int e1 = stack.pop();
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(e1, 100);
    int e2 = stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(e2, 10);
    int e3 = stack.pop();
    EXPECT_EQ(e3,1);
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, itShouldPeekStack){
    Stack<int> stack;
    stack.push(1);
    int e1 = stack.peek();
    EXPECT_EQ(e1, 1);
    EXPECT_EQ(stack.size(), 1);
}

bool isPalindrome(string x) {
      Stack<char> stack(x);
      int i = 0;
      while (!stack.isEmpty()) {
          if (toupper(x[i++]) != toupper(stack.pop())) {
              return false;
          }
      }
    return true;
}

TEST(StackTest, itShouldBeAPalindrome
){
EXPECT_TRUE(isPalindrome("ANA")
);
EXPECT_FALSE(isPalindrome("An")
);
EXPECT_TRUE(isPalindrome("ana")
);
EXPECT_TRUE(isPalindrome("Ana")
);
EXPECT_TRUE(isPalindrome("oso")
);
EXPECT_TRUE(isPalindrome("solos")
);
}

TEST(StackTest, itShouldCreateAnStackFactory
) {
Stack<int> *stack = Stack<int>::Factory(10);
EXPECT_TRUE(!stack->

isEmpty()

);
}

TEST(StackTest, itShouldForEach
) {
Stack<int> *stack = Stack<int>::Factory(10);
stack->forEach([](
int element,
int index
) {
EXPECT_GE(element,
10);
});
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}