//
// Created by sanchezcarlosjr on 11/20/21.
//
#include <string>
using namespace std;

class Solution {
private:
    unsigned short int converter[100][100][100];
public:
    Solution() {
        converter[73][0][0] = 1;
        converter[73][73][0] = 2;
        converter[73][73][73] = 3;
        converter[73][86][0] = 4;
        converter[86][0][0] = 5;
        converter[86][73][0] = 6;
        converter[86][73][73] = 7;
        converter[73][88][0] = 9;
        converter[88][0][0] = 10;
        converter[88][73][0] = 11;
        converter[88][73][73] = 12;
        converter[88][73][86] = 14;
        converter[88][86][0] = 15;
        converter[88][86][73] = 16;
        converter[88][88][0] = 20;
        converter[88][88][88] = 30;
        converter[76][0][0] = 50;
        converter[76][88][88] = 70;
        converter[67][0][0] = 100;
        converter[67][67][0] = 200;
        converter[67][67][67] = 300;
        converter[68][0][0] = 500;
        converter[77][0][0] = 1000;
        converter[88][76][0] = 40;
        converter[88][67][0] = 90;
        converter[67][68][0] = 400;
        converter[67][77][0] = 900;
    }
    unsigned short int romanToInt(const string& s) {
        unsigned short int sum = 0;
        unsigned char  i = 0;
        unsigned char n = s.length();
        while (i < n) {
            sum += converterA(s, &i);
            i = i + 1;
        }
        return sum;
    }

    unsigned short int converterA(const string& symbols, unsigned char *i) {
        unsigned short int x = converter[symbols[*i]][symbols[*i+1]][symbols[*i+2]];
        if (x != 0) {
            *i = *i + 2;
            return x;
        }
        x = converter[symbols[*i]][symbols[*i+1]][0];
        if (x != 0) {
            *i = *i + 1;
            return x;
        }
        return converter[symbols[*i]][0][0];
    }
};