#include <gtest/gtest.h>

#include "Recursion.hpp"

namespace
{

TEST(RecursionTests, DISABLED_FactorialBaseCase)
{
	EXPECT_EQ(algorithms::Factorial(0), 1);
	EXPECT_EQ(algorithms::Factorial(1), 1);
}

TEST(RecursionTests, DISABLED_FactorialSmallValues)
{
	EXPECT_EQ(algorithms::Factorial(5), 120);
	EXPECT_EQ(algorithms::Factorial(10), 3628800);
}

TEST(RecursionTests, DISABLED_ReverseStringEmpty)
{
	EXPECT_EQ(algorithms::ReverseString(""), "");
}

TEST(RecursionTests, DISABLED_ReverseStringBasic)
{
	EXPECT_EQ(algorithms::ReverseString("hello"), "olleh");
	EXPECT_EQ(algorithms::ReverseString("a"), "a");
}

TEST(RecursionTests, DISABLED_NQueensSize1)
{
	auto solutions = algorithms::SolveNQueens(1);
	EXPECT_EQ(solutions.size(), 1u);
}

TEST(RecursionTests, DISABLED_NQueensSize4)
{
	auto solutions = algorithms::SolveNQueens(4);
	EXPECT_EQ(solutions.size(), 2u); // 4-Queens has exactly 2 solutions
}

}  // namespace
