//
// Created by cest on 5/5/21.
//

#include "StdoutMock.h"

StdoutMock::StdoutMock() {
    testing::internal::CaptureStdout();
    istringstream input("");
    cin.rdbuf(input.rdbuf());
}

void StdoutMock::assert_eq(string expected) {
    string actual = testing::internal::GetCapturedStdout();
    ASSERT_EQ(actual, expected);
}

vector<string> StdoutMock::split(string splitter = ".*\n") {
    string actual = testing::internal::GetCapturedStdout();
    return matches(actual, splitter);
}

void StdoutMock::assert_eq(initializer_list<string> expectedList) {
    vector<string> actual = this->split();
    int i = 0;
    for (string expected : expectedList) {
        ASSERT_EQ(actual[i], expected);
        i++;
    }
}
