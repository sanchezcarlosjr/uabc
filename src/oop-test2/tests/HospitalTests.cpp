#include <gtest/gtest.h>
#include "../src/Hospital.h"

TEST(Hospital, itShouldBeEmpty
) {
Hospital hospital;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}