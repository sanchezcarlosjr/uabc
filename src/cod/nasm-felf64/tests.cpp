#include <gtest/gtest.h>

extern "C" int64_t maxofthree(int64_t, int64_t, int64_t);
extern "C" int sayHello();

TEST(Practice1Test, maxofthreetest
) {
    ASSERT_EQ(1,    maxofthree(1, -4, -7));
}

TEST(Practice2Test, sayHelloTest
) {
    ASSERT_EQ(5,    sayHello());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}