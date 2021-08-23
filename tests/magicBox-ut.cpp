#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "magicBox.hpp"
#include <string>

class TestMagicBox : public ::testing::Test {
public:
	MagicBox magicBox;
};

TEST_F(TestMagicBox, MethodGetIdBoxSizeShouldReturn0WhenMagicBoxIsInitialized){
	EXPECT_EQ(magicBox.getIdBoxSize(), 0);
}

TEST_F(TestMagicBox, MethodDrawIdShouldDrawNumbersIdWhichIsUniqueInTheSetAndReturnIt){
	std::set<int> expectedMagicBox {1,2,3,4,5,6,7,8,9};
	std::set<int> workingMagicBox;
	for(int i{0}; i < 9; ++i){
		workingMagicBox.insert(magicBox.drawId());
	}
	EXPECT_EQ(expectedMagicBox, workingMagicBox);
}
