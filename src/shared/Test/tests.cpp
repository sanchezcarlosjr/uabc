#include <gtest/gtest.h>
#include <iostream>
#include "StdoutMock.h"
using namespace std;

TEST(StdoutTest, itShouldAssertCout) {
    StdoutMock stdoutMock;
    cout << "ABCD123";
    stdoutMock.assert_eq("ABCD123");
}

TEST(StdoutTest, itShouldAssertNewline) {
    StdoutMock stdoutMock;
    cout << "1\n";
    cout << "2\n";
    cout << "3\n";
    stdoutMock.assert_eq({"1\n", "2\n", "3\n"});
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}