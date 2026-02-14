#include <gtest/gtest.h>

#include "DynamicProgramming.hpp"

namespace
{

TEST(DynamicProgrammingTests, DISABLED_FibonacciBaseCases)
{
	EXPECT_EQ(algorithms::FibonacciDP(0), 0);
	EXPECT_EQ(algorithms::FibonacciDP(1), 1);
}

TEST(DynamicProgrammingTests, DISABLED_FibonacciSmallValues)
{
	EXPECT_EQ(algorithms::FibonacciDP(10), 55);
	EXPECT_EQ(algorithms::FibonacciDP(20), 6765);
}

TEST(DynamicProgrammingTests, DISABLED_MakeChangeBasic)
{
	EXPECT_EQ(algorithms::MakeChange(11, {1, 5, 6}), 2); // 5 + 6
}

TEST(DynamicProgrammingTests, DISABLED_MakeChangeImpossible)
{
	EXPECT_EQ(algorithms::MakeChange(3, {2}), -1);
}

TEST(DynamicProgrammingTests, DISABLED_LCSBasic)
{
	auto lcs = algorithms::LongestCommonSubsequence("abcde", "ace");
	EXPECT_EQ(lcs, "ace");
}

TEST(DynamicProgrammingTests, DISABLED_LCSNoCommon)
{
	auto lcs = algorithms::LongestCommonSubsequence("abc", "xyz");
	EXPECT_EQ(lcs, "");
}

}  // namespace
