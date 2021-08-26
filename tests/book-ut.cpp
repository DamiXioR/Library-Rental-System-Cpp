#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "book.hpp"
#include <string>

TEST(TestBook, GettersShouldReturnsBooksAuthorTitleKindDate){
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021, 1};

	EXPECT_EQ(lordOfTheRings.getAuthor(), "Tolkien");
	EXPECT_EQ(lordOfTheRings.getTitle(), "Lord of the ring");
	EXPECT_EQ(lordOfTheRings.getKind(), "Fantasy");
	EXPECT_EQ(lordOfTheRings.getDate(), 2021);
	EXPECT_EQ(lordOfTheRings.getId(), 1);
}

TEST(TestBook, MethodGetStringStreamOfBooksDataShoudReturnSStreamWithLoadedWithBooksData){
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021, 1};

	std::stringstream expectedStringStream; 
	expectedStringStream << "Title: " << "Lord of the ring" << " Kind: " << "Fantasy" << " Date: " << 2021 << " ID: " << 1;

	EXPECT_EQ(expectedStringStream.str(), lordOfTheRings.getStringStreamOfBooksData().str());	
}
