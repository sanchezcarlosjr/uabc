#include <gtest/gtest.h>
#include "../DataStructure.h"
#include <iostream>

using namespace std;

TEST(SUTTest, itShouldBeEmpty
) {
List<int> list;
ASSERT_TRUE(list
.

isEmpty()

);
}

TEST(SUTTest, itShouldNotBeEmpty
) {
List<int> list;
list.push(1);
ASSERT_FALSE(list
.

isEmpty()

);
}

TEST(SUTTest, itShouldForEachList
) {
List<int> *list = List<int>::Factory(10);
ASSERT_TRUE(!list->

isEmpty()

);
ASSERT_EQ(list
->

size(),

10);
list->forEach([](
int element,
int index
) {
ASSERT_GE(element,
10);
});
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}