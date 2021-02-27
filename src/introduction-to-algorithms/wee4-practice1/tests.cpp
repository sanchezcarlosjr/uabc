#include "DataStructure.h"
#include <gtest/gtest.h>

TEST(Queue, itShouldBeEmpty){
    Queue<int> queue;
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_EQ(queue.size(), 0);
}

TEST(StackTest, itShouldEnqueue){
    Queue<int> queue;
    queue.enqueue(1);
    EXPECT_FALSE(queue.isEmpty());
}

TEST(StackTest, itShouldDequeue){
    Queue<int> queue;
    queue.enqueue(1);
    EXPECT_FALSE(queue.isEmpty());
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}