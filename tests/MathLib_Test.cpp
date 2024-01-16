#include <MathLib/Mathlib.h>
#include <Gtest/gtest.h>

TEST(MathTest, add_int_test1)
{
	const int expected = 8;
	const int actual = MathLib::add_int(3, 5);
	ASSERT_EQ(expected, actual);
}

TEST(MathTest, add_int_test2)
{
	const int expected = 15;
	const int actual = MathLib::add_int(7, 8);
	ASSERT_EQ(expected, actual);
}

TEST(MathTest, add_int_test3)
{
	const int expected = 13;
	const int actual = MathLib::add_int(8, 5);
	ASSERT_EQ(expected, actual);
}

TEST(MathTest, add_int_test4)
{
	const int expected = 8;
	const int actual = MathLib::add_int(2, 6);
	ASSERT_EQ(expected, actual);
}