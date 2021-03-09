#include <gtest/gtest.h>
#include "../DataStructure.h"

TEST(SUTTest, itShouldBeEmpty) {
    List<int> list;
    ASSERT_TRUE(list.isEmpty());
}

TEST(SUTTest, itShouldNotBeEmpty) {
    List<int> list;
    list.push(1);
    ASSERT_FALSE(list.isEmpty());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}