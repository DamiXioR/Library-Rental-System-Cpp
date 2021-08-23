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
	EXPECT_EQ(magicBox.drawId(), 1);
}
