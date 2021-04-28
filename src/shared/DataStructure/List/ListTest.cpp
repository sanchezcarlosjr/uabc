#include <gtest/gtest.h>
#include "../DataStructure.h"
#include <iostream>

using namespace std;

TEST(ListTest, itShouldBeEmpty) {
    List<int> list;
    ASSERT_TRUE(list.isEmpty());
}

TEST(ListTest, itShouldNotBeEmptyWhenItPush) {
    List<int> list;
    list.push(1);
    ASSERT_FALSE(list.isEmpty());
}

TEST(ListTest, itShouldGetElementInNPosition) {
    List<int> list;
    list.push(1);
    ASSERT_EQ(1,list[0]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}