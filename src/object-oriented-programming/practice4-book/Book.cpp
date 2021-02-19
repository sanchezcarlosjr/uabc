//
// Created by cest on 19/02/21.
//

#include "Book.h"

Book::Book(string title, int year) {
    this->title = title;
    this->year = year;
}

Book::Book(int year, string title) {
    Book(title, year);
}

bool Book::is(State state) {
    return this->state == state;
}

bool Book::changeStateTo(State state) {
    if (this->is(state) && !this->is(AVAILABLE)) {
        return false;
    }
    this->state = state;
    return true;
}

bool Book::borrow() {
    return this->changeStateTo(LOAN);
}

bool Book::reserve() {
    return this->changeStateTo(RESERVED);
}

bool Book::returnBook() {
    return this->changeStateTo(AVAILABLE);
}

string Book::toString() {
    return "Book's name is A and it's published in 9";
}