#include <gtest/gtest.h>
#include "RPN.h"

namespace {
	TEST(NothingTest, NoTest) {
		EXPECT_EQ(0, calculate(""));
		EXPECT_EQ("", parse(""));
	}

	TEST(CalculateTest, Addition) {
		EXPECT_EQ(4, calculate("2 2 + "));
		EXPECT_EQ(123, calculate("113 10 + "));
	}
	TEST(CalculateTest, Subtraction) {
		EXPECT_EQ(0, calculate("4 4 - "));
		EXPECT_EQ(100, calculate("110 10 - "));
	}
	TEST(CalculateTest, Multiplication) {
	       EXPECT_EQ(4, calculate("2 2 * "));
	       EXPECT_EQ(1000, calculate("100 10 *"));
	}	       
	TEST(CalculateTest, Division) {
		EXPECT_EQ(1, calculate("4 4 / "));
		EXPECT_EQ(5, calculate("40 8 /"));
	}

	TEST(CombinedTest, ComplexTest) {
		EXPECT_EQ(3.5, calculate(parse("3 + 4 * 2 / (1 - 5) ^ 2")));
	}
}
