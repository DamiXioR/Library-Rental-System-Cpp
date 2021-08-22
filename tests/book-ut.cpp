#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "book.hpp"
#include <string>

TEST(TestBook, GettersShouldReturnsBooksAuthorTitleKindDate){
	Book lordOfTheRings = Book {"Tolkien", "Lord of the ring", "Fantasy", 2021};

	EXPECT_EQ(lordOfTheRings.getAuthor(), "Tolkien");
	EXPECT_EQ(lordOfTheRings.getTitle(), "Lord of the ring");
	EXPECT_EQ(lordOfTheRings.getKind(), "Fantasy");
	EXPECT_EQ(lordOfTheRings.getDate(), 2021);
}
