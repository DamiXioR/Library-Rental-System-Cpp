#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "magicBox.hpp"
#include "magicBoxStub.hpp"

#include <string>

class TestMagicBox : public ::testing::Test {
public:
	MagicBox magicBox;
};

class TestMagicBoxStub : public ::testing::Test {
public:
	MagicBoxStub magicBoxStub;
};

TEST_F(TestMagicBox, MethodGetIdBoxSizeShouldReturn0WhenMagicBoxIsInitialized){
	EXPECT_EQ(magicBox.getIdBoxSize(), 0);
}

TEST_F(TestMagicBoxStub, MethodDrawIdShouldDrawNumbersIdWhichIsUniqueInTheSetAndReturnIt){
	std::set<int> expectedMagicBox;
	for(int i{1}; i<51; ++i){
		expectedMagicBox.insert(i);
	}
	std::set<int> workingMagicBox;
	for(int i{1}; i < 51; ++i){
		workingMagicBox.insert(magicBoxStub.drawId());
	}
	EXPECT_EQ(expectedMagicBox, workingMagicBox);
}
