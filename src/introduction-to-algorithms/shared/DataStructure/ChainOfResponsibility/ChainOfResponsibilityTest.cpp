#include <gtest/gtest.h>
#include "ListHandler.h"
#include "NodeHandlerAMock.h"
#include "NodeHandlerBMock.h"

TEST(ListHandler, itShouldNotBeEmpty){
    ListHandler<int, int> listHandler({new NodeHandlerAMock(), new NodeHandlerBMock()});
    ASSERT_EQ(listHandler.execute(1), 10);
    ASSERT_EQ(listHandler.execute(-1), -10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}