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

Book::~Book() {
    cout << this->toString() << " has removed.";
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
    stringstream s;
    s << "Book's name is " << this->title << " and it's published in "<<this->year;
    return s.str();
}