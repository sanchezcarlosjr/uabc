//
// Created by cest on 19/02/21.
//
#include "Book.h"
#include "system.h"
#include <vector>

#ifndef UABC_LIBRARY_H
#define UABC_LIBRARY_H

class Library {
private:
    vector<Book*> library;
public:
    void add() {
        string title = print<string>("Title: ");
        int year = print<int>("Year: ");
        this->library.push_back(new Book(title, year));
    }
    void borrow() {
        int index = print<int>("Which book do you want to borrow? ");
        if (this->library[index]->borrow()) {
            cout << "Successful!!";
        }
        else {
            cout << "Try again!";
        }
    }
    void returnBook() {
        int index = print<int>("Which book do you want to return? ");
        this->library[index]->returnBook();
        cout << "Successful!!";
    }
    void reserve() {
        int index = print<int>("Which book do you want to reserve? ");
        this->library[index]->reserve();
        cout << "Successful!!";
    }
    void removeLast() {
        this->library.pop_back();
        cout << "Successful!!";
    }
};

#endif //UABC_LIBRARY_H
