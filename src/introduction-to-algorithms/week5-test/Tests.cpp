#include <gtest/gtest.h>
#include "SumPrimesAlgorithm.h"
#include <list>

TEST(SumPrimesTest, itShouldCalculateSumPrimes){
    int myints[] = {1,2,3,4,-1};
    std::list<int> integers (myints, myints + sizeof(myints) / sizeof(int) );
    ASSERT_EQ(5, sumPrimes(integers));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}