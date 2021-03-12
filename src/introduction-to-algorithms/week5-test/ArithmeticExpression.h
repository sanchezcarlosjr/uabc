//
// Created by cest on 09/03/21.
//
#include "DataStructure/DataStructure.h"

#ifndef UABC_ARITHMETICEXPRESSION_H
#define UABC_ARITHMETICEXPRESSION_H

bool isBalancedExpression(string expression) {
    Stack<char> stack;
    for (char &c : expression) {
        if (c == '{' || c == '[' || c == '(') {
            stack.push(c);
            continue;
        }
        if (
                c == '}' && stack.peek() != '{' ||
                c == ']' && stack.peek() != '[' ||
                c == ')' && stack.peek() != '('
                ) {
            return false;
        }
        if (
                c == '}' && stack.peek() == '{' ||
                c == ']' && stack.peek() == '[' ||
                c == ')' && stack.peek() == '('
                ) {
            stack.pop();
        }
    }
    return stack.isEmpty();
}

#endif //UABC_ARITHMETICEXPRESSION_H
