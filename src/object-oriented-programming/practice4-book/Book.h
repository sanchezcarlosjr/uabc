//
// Created by cest on 19/02/21.
//
#include <string>

using namespace std;

#ifndef UABC_BOOK_H
#define UABC_BOOK_H

enum State { AVAILABLE, RESERVED, LOAN };

class Book {
private:
    string title;
    int year;
    State state = AVAILABLE;
    bool changeStateTo(State state);
    bool is(State state);
public:
    Book(string, int);
    Book(int, string);
    bool borrow();
    bool reserve();
    bool returnBook();
    string toString();
};


#endif //UABC_BOOK_H
