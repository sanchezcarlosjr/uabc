//
// Created by cest on 5/6/21.
//

#include "ToString.h"

template<class T>
string toString(vector<T> vec, string split) {
    ostringstream vts;
    if (!vec.empty())
    {
        std::copy(vec.begin(), vec.end()-1, ostreambuf_iterator<T>(vts, split));
        vts << vec.back();
    }
    return vts.str();
}