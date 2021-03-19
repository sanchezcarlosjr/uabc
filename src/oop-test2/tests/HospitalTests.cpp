#include <gtest/gtest.h>
#include "../src/Hospital.h"

TEST(Hospital, itShouldCreateRooms
) {
testing::internal::CaptureStdout();

istringstream input("5");
cin.
rdbuf(input
.

rdbuf()

);
Hospital hospital;
string output = testing::internal::GetCapturedStdout();
ASSERT_EQ(output,
"How many rooms do you start hospital?");
ASSERT_EQ(hospital
.

getSize(),

5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}