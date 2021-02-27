#include "DataStructure.h"
#include <gtest/gtest.h>

TEST(Queue, itShouldBeEmpty){
    Queue<bool> queue;
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_EQ(queue.size(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}