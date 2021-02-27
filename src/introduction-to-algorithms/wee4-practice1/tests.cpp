#include <gtest/gtest.h>
#include "Queue.h"

TEST(Queue, itShouldBeEmpty){
    Queue<int> queue;
    ASSERT_TRUE(queue.isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}