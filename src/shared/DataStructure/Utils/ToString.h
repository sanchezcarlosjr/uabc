//
// Created by cest on 5/6/21.
//
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;
#ifndef OOP_TEST3_TOSTRING_H
#define OOP_TEST3_TOSTRING_H

template<class T>
string toString(vector<int> vec) {
    std::ostringstream oss;
    if (!vec.empty())
    {
        std::copy(vec.begin(), vec.end()-1,
                  std::ostream_iterator<int>(oss, " "));
        oss << vec.back();
    }
    return oss.str();
}


#endif //OOP_TEST3_TOSTRING_H
