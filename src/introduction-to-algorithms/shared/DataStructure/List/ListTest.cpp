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

TEST(ListTest, itShouldNotBeEmpty
) {
List<int> list;
list.push(1);
ASSERT_FALSE(list
.

isEmpty()

);
}

TEST(ListTest, itShouldMapList
) {
List<int> *list = List<int>::Factory(10);
list->map([](
int element,
int index
) {
return element * 2;
})->forEach([](
int element,
int index
) {
cout << element << "\n";
});
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}