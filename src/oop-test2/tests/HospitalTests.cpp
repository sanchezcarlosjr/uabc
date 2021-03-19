#include <gtest/gtest.h>
#include "../src/Hospital.h"

TEST(Hospital, itShouldBeEmpty
) {
testing::internal::CaptureStdout();

std::istringstream input("5");
std::cin.
rdbuf(input
.

rdbuf()

);
Hospital hospital;
string output = testing::internal::GetCapturedStdout();
ASSERT_EQ(output,
"How many rooms do you start hospital?");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}