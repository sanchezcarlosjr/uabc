#include "Book.h"
#include <gtest/gtest.h>

TEST(Student, itShouldReturnTrueIfYouCanBorrowBook){
    Book* book = new Book("A", 9);
    EXPECT_TRUE(book->borrow());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}