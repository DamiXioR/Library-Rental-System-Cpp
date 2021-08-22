#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shelf.hpp"
#include <string>

TEST(TestShelf, MethodGetShelfShouldReturnEmptyShelfWhenIsInitialized){
	Shelf shelf;
	
	EXPECT_TRUE(shelf.isShelfEmpty());
}
