#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shelf.hpp"
#include <string>
#include <type_traits>

class TestShelf : public ::testing::Test {
public:
//Shelves+
	Shelf shelf;

//Books
	Book lordOfTheRings = Book {"Tolkien", "Lord of the rings", "Fantasy", 2021, 1};
	Book hobbit = Book {"Tolkien", "Hobbit", "Fantasy", 2020, 2};
	Book diuna = Book {"Herbert", "Diuna", "Fantasy", 2019, 3};
	Book hyperion = Book {"Simmons", "Hyperion", "Fantasy", 2018, 4};
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

	shelf.putTheBookOnTheShelf(hobbit);
	shelf.putTheBookOnTheShelf(diuna);
	EXPECT_EQ(shelf.getBooksCount(), 3);
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsFalseWhenBookNotFounded){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Diuna");

	EXPECT_FALSE(foundedPair.first);
}

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByTitleShouldReturnPairWhereFirstElementIsTrueWhenBookIsFoundedAndSecondElementIsIteratorToTheBook){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	auto foundedPair = shelf.findTheBookOnTheShelfByTitle("Lord of the rings");
	
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

TEST_F(TestShelf, MethodFindTheBookOnTheShelfByIdShouldReturnPairWhereFirstElementIsTrueWhenBookIsFoundedAndSecondElementIsIteratorToTheBook){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	shelf.putTheBookOnTheShelf(hobbit);
	shelf.putTheBookOnTheShelf(diuna);
	shelf.putTheBookOnTheShelf(hyperion);
	
	auto foundedPair = shelf.findTheBookOnTheShelfById(100);
	EXPECT_FALSE(foundedPair.first);
	
	foundedPair = shelf.findTheBookOnTheShelfById(2);
	EXPECT_TRUE(foundedPair.first);
	EXPECT_EQ(foundedPair.second->getTitle(),hobbit.getTitle());
}

TEST_F(TestShelf, MethodRemoveTheBookFromTheShelfByIdShouldRemoveTheBookSoBooksCountDecreaseAndItsNoMorePossibleToFindBookById){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	shelf.putTheBookOnTheShelf(hobbit);
	shelf.putTheBookOnTheShelf(diuna);
	shelf.putTheBookOnTheShelf(hyperion);
	EXPECT_EQ(shelf.getBooksCount(), 4);

	shelf.removeTheBookFromTheShelfById(3);
	EXPECT_EQ(shelf.getBooksCount(), 3);

	auto foundedPair = shelf.findTheBookOnTheShelfById(3);
	EXPECT_FALSE(foundedPair.first);
}


TEST_F(TestShelf, MethodRemoveTheBookFromTheShelfByIdShouldRemoveTheBookIfExistsSoIfNotExistsItShouldDoNothing){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	shelf.putTheBookOnTheShelf(hobbit);
	shelf.putTheBookOnTheShelf(diuna);
	shelf.putTheBookOnTheShelf(hyperion);
	EXPECT_EQ(shelf.getBooksCount(), 4);
	
	shelf.removeTheBookFromTheShelfById(100);
	EXPECT_EQ(shelf.getBooksCount(), 4);
}

TEST_F(TestShelf, MethodRemoveTheBookFromTheShelfByIdShouldRemoveTheBookSoWhenAllBooksAreRemovedShelfShouldBeEmpty){
	shelf.putTheBookOnTheShelf(lordOfTheRings);
	shelf.putTheBookOnTheShelf(hobbit);
	shelf.putTheBookOnTheShelf(diuna);
	shelf.putTheBookOnTheShelf(hyperion);
	
	shelf.removeTheBookFromTheShelfById(1);
	shelf.removeTheBookFromTheShelfById(2);
	shelf.removeTheBookFromTheShelfById(3);
	shelf.removeTheBookFromTheShelfById(4);

	EXPECT_TRUE(shelf.isShelfEmpty());	
}
