#include <gtest/gtest.h>
#include "SumPrimesAlgorithm.h"
#include "PermutationAlgorithm.h"
#include "DataStructure/DataStructure.h"

TEST(SumPrimesTest, itShouldCalculateSumPrimes){
    Stack<int> stack({1,2,3,4,6});
    ASSERT_EQ(5, sumPrimes(stack));
}

TEST(PermutationTest, itShouldShowPermutationWhenItIsHasMoreAElement){
   ASSERT_EQ("", permute(""));
   ASSERT_EQ("A\n", permute("A"));
   ASSERT_EQ("AB\nBA\n", permute("AB"));
   ASSERT_EQ("ABC\nACB\nBAC\nBCA\nCAB\nCBA\n", permute("ABC"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}