#include <gtest/gtest.h>
#include "../DataStructure.h"
#include <iostream>

using namespace std;

TEST(ListTest, itShouldBeEmpty
) {
List<int> list;
ASSERT_TRUE(list
.

isEmpty()

);
}

TEST(ListTest, itShouldNotBeEmptyWhenItPush
) {
List<int> list;
list.push(1);
ASSERT_FALSE(list
.

isEmpty()

);
}

TEST(ListTest, itShouldBuildWhenListPassByParameter
) {
int array[] = {1, 2, 3, 4, 5};
List<int> list({1, 2, 3, 4, 5});
ASSERT_FALSE(list
.

isEmpty()

);
list.forEach([array](
int element,
int index
){
ASSERT_EQ(array[index - 1], element
);
});
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}