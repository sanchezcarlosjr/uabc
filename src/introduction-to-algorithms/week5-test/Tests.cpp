#include <gtest/gtest.h>
#include "SumPrimesAlgorithm.h"
#include "DataStructure/DataStructure.h"

TEST(SumPrimesTest, itShouldCalculateSumPrimes){
    Stack<int> stack({1,2,3,4,6});
    ASSERT_EQ(5, sumPrimes(stack));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}