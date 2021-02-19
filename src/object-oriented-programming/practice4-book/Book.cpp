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

bool Book::borrow() {
    return true;
};