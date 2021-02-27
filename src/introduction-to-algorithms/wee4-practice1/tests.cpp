#include "DataStructure.h"
#include <gtest/gtest.h>

TEST(Queue, itShouldBeEmpty){
    Queue<int> queue;
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_EQ(queue.size(), 0);
}

TEST(StackTest, itShouldNotBeEmpty){
    Queue<int> queue;
    queue.enqueue(1);
    EXPECT_FALSE(queue.isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}