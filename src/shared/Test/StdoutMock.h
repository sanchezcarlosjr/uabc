//
// Created by cest on 5/5/21.
//
#include <iostream>
#include <vector>
#include <string>
#include "../RegexLib/RegexLib.h"

#include <gtest/gtest.h>

using namespace std;

#ifndef OOP_TEST3_STDOUTMOCK_H
#define OOP_TEST3_STDOUTMOCK_H


class StdoutMock {
private:
    string capturedStdout;

    string getCapturedStdout();

public:
    StdoutMock();

    void assert_eq(const string &expected);

    void assert_eq(initializer_list<string>);

    vector<string> split(const string &splitter);

};


#endif //OOP_TEST3_STDOUTMOCK_H
