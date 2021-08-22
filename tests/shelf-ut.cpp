#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shelf.hpp"
#include <string>

class TestShelf : public ::testing::Test {
public:
	Shelf shelf;
};

TEST_F(TestShelf, MethodGetShelfShouldReturnEmptyShelfWhenIsInitialized){
	EXPECT_TRUE(shelf.isShelfEmpty());
}

TEST_F(TestShelf, MethodGetBooksCountShouldReturn0BooksWhenIsInitialized){
	EXPECT_EQ(shelf.getBooksCount(), 0);
}
