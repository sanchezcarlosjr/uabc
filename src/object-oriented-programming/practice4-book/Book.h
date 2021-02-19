//
// Created by cest on 19/02/21.
//
#include <string>

using namespace std;

#ifndef UABC_BOOK_H
#define UABC_BOOK_H

enum State { AVAILABLE, RESERVE, BORROWED };

class Book {
private:
    string title;
    int year;
    State state = AVAILABLE;
public:
    Book(string, int);
    Book(int, string);
    bool borrow();
};


#endif //UABC_BOOK_H
