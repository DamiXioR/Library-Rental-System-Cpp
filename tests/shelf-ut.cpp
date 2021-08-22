#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shelf.hpp"
#include <string>
#include <type_traits>

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

TEST_F(TestShelf, MethodPutTheBookOnTheShelfMakesThatShelfIsNoMoreEmptyAlsoIncreaseBooksCountAlso){
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021};
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	
	EXPECT_FALSE(shelf.isShelfEmpty());
	EXPECT_EQ(shelf.getBooksCount(), 1);
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsFalseWhenBookNotFounded){
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021};
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Diuna");

	EXPECT_FALSE(foundedPair.first);
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsTrueWhenBookIsFoundedAndSecondElementIsIteratorToTheBook){
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021};
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Lord of the ring");
	
	EXPECT_TRUE(foundedPair.first);
	EXPECT_EQ(foundedPair.second->getTitle(),lordOfTheRings.getTitle());
}
