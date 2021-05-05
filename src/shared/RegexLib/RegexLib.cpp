//
// Created by cest on 5/5/21.
//

#include "RegexLib.h"

vector<string> matches(string s, const string& regularExpression) {
    vector<string> vector;
    smatch m;
    regex e (regularExpression);
    while (std::regex_search (s,m,e)) {
        for (auto x:m) vector.push_back(x);
        s = m.suffix().str();
    }
    return vector;
}