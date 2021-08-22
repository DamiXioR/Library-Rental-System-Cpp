#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "randomClass.hpp"

class TestingRandomClass : public ::testing::Test {
public:
	RandomClass rC;

};

TEST_F(TestingRandomClass, MethodIsRandomClassWorksShouldReturnAlwaysTrue){
	ASSERT_TRUE(rC.isRandomClassWorks());
}
