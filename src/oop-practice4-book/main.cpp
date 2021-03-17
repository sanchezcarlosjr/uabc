/*
        Library
        Created by Carlos Sanchez
        Created at 19/02/21
*/

#include "Library.h"

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
