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
    EXPECT_EQ(queue.size(),1);
    queue.enqueue(10);
    EXPECT_EQ(queue.size(),2);
    queue.enqueue(100);
    EXPECT_EQ(queue.size(),3);
    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.size(),3);
    EXPECT_EQ(queue.dequeue(),1);
    EXPECT_EQ(queue.dequeue(),10);
    EXPECT_EQ(queue.dequeue(),100);
    EXPECT_TRUE(queue.isEmpty());
    queue.enqueue(1);
    EXPECT_EQ(queue.size(),1);
    EXPECT_EQ(queue.dequeue(),1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}