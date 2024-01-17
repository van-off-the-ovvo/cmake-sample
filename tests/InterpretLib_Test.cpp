#include "InterpretLib/InterpretLib.h"
#include <Gtest/gtest.h>

TEST(InterpretTest, interpret_test1)
{
	const std::string expected = "3 + 5 = ";
	const std::string actual = InterpretLib::interpret_add(3, 5);
	ASSERT_EQ(expected, actual);
}

TEST(InterpretTest, interpret_test2)
{
	const std::string expected = "12 + 54 = ";
	const std::string actual = InterpretLib::interpret_add(12, 54);
	ASSERT_EQ(expected, actual);
}