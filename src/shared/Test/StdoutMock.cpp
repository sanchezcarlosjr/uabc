//
// Created by cest on 5/5/21.
//

#include "StdoutMock.h"

StdoutMock::StdoutMock() {
    testing::internal::CaptureStdout();
    istringstream input("");
    cin.rdbuf(input.rdbuf());
}

void StdoutMock::assert_eq(const string& expected) {
    string actual = this->getCapturedStdout();
    ASSERT_EQ(actual, expected);
}

vector<string> StdoutMock::split(const string& splitter = ".*\n") {
    string actual = this->getCapturedStdout();
    return matches(actual, splitter);
}

void StdoutMock::assert_eq(initializer_list<string> expectedList) {
    vector<string> actual = this->split();
    int i = 0;
    for (const string& expected : expectedList) {
        ASSERT_TRUE(regex_match(actual[i], regex(expected)));
        i++;
    }
}

string StdoutMock::getCapturedStdout() {
    this->capturedStdout = this->capturedStdout.empty() ? testing::internal::GetCapturedStdout() : this->capturedStdout;
    return this->capturedStdout;
}