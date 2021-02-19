/*
        Library
        Created by Carlos Sanchez
        Created at 19/02/21
*/

#include "Book.h"
#include "system.h"
#include <vector>

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


int main() {
    Library* library = new Library();
    library->add();
    library->borrow();
    library->borrow();
    library->returnBook();
    library->reserve();
    library->reserve();
    library->returnBook();
    library->removeLast();
    return 0;
}
