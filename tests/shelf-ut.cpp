#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shelf.hpp"
#include <string>
#include <type_traits>

class TestShelf : public ::testing::Test {
public:
//Shelves
	Shelf shelf;

//Books
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021};
	Book hobbit = Book {"Tolkien", "Hobbit", "Fantasy", 2020};
	Book diuna = Book {"Herbert", "Diuna", "Fantasy", 2019};
	Book hyperion = Book {"Simmons", "Hyperion", "Fantasy", 2018};
};

TEST_F(TestShelf, MethodGetShelfShouldReturnEmptyShelfWhenIsInitialized){
	EXPECT_TRUE(shelf.isShelfEmpty());
}

TEST_F(TestShelf, MethodGetBooksCountShouldReturn0BooksWhenIsInitialized){
	EXPECT_EQ(shelf.getBooksCount(), 0);
}

TEST_F(TestShelf, MethodPutTheBookOnTheShelfMakesThatShelfIsNoMoreEmptyAlsoIncreaseBooksCountAlso){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	
	EXPECT_FALSE(shelf.isShelfEmpty());
	EXPECT_EQ(shelf.getBooksCount(), 1);
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsFalseWhenBookNotFounded){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Diuna");

	EXPECT_FALSE(foundedPair.first);
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsTrueWhenBookIsFoundedAndSecondElementIsIteratorToTheBook){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Lord of the ring");
	
	EXPECT_TRUE(foundedPair.first);
	EXPECT_EQ(foundedPair.second->getTitle(),lordOfTheRings.getTitle());
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsTrueWhenBookIsFoundedAndSecondElementIsIteratorToTheBook2){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	shelf.putTheBookOnTheShelf(hobbit);
	shelf.putTheBookOnTheShelf(diuna);
	shelf.putTheBookOnTheShelf(hyperion);

	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Fantasy");
	EXPECT_FALSE(foundedPair.first);
	
	foundedPair = shelf.findTheBookOnTheShelfByTitle("Hyperion");
	EXPECT_TRUE(foundedPair.first);
	EXPECT_EQ(foundedPair.second->getTitle(),hyperion.getTitle());
}
