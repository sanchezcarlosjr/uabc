#include "Book.h"
#include <gtest/gtest.h>

TEST(Student, itShouldReturnTrueIfBookHasNotBeenBorrowed){
    Book* book = new Book("A", 9);
    EXPECT_TRUE(book->borrow());
}

TEST(Student, itShouldReturnFalseIfBookHasBeenBorrowed){
    Book* book = new Book("A", 9);
    book->borrow();
    EXPECT_FALSE(book->borrow());
}

TEST(Student, itShouldReturnTrueIfBookHasNotBeenReserved){
    Book* book = new Book("A", 9);
    EXPECT_TRUE(book->reserve());
}

TEST(Student, itShouldReturnFalseIfBookHasBeenReserved){
    Book* book = new Book("A", 9);
    book->reserve();
    EXPECT_FALSE(book->reserve());
}

TEST(Student, itShouldReturnTrueIfBookHasBeenReturn){
    Book* book = new Book("A", 9);
    EXPECT_TRUE(book->reserve());
}

TEST(Student, itShouldReturnTrueIfBookHasBeenTwoTimesReturn){
    Book* book = new Book("A", 9);
    book->returnBook();
    EXPECT_TRUE(book->returnBook());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}