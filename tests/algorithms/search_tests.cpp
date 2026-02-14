#include <gtest/gtest.h>

#include <vector>

#include "Search.hpp"

namespace
{

TEST(SearchTests, DISABLED_LinearSearchFindsElement)
{
	std::vector<int> v{3, 1, 4, 1, 5};
	auto it = algorithms::LinearSearch(v.begin(), v.end(), 4);
	ASSERT_NE(it, v.end());
	EXPECT_EQ(*it, 4);
}

TEST(SearchTests, DISABLED_LinearSearchMissing)
{
	std::vector<int> v{3, 1, 4, 1, 5};
	auto it = algorithms::LinearSearch(v.begin(), v.end(), 99);
	EXPECT_EQ(it, v.end());
}

TEST(SearchTests, DISABLED_BinarySearchFindsElement)
{
	std::vector<int> v{1, 3, 5, 7, 9};
	auto it = algorithms::BinarySearch(v.begin(), v.end(), 5);
	ASSERT_NE(it, v.end());
	EXPECT_EQ(*it, 5);
}

TEST(SearchTests, DISABLED_BinarySearchMissing)
{
	std::vector<int> v{1, 3, 5, 7, 9};
	auto it = algorithms::BinarySearch(v.begin(), v.end(), 4);
	EXPECT_EQ(it, v.end());
}

TEST(SearchTests, DISABLED_SearchEmptyRange)
{
	std::vector<int> v;
	EXPECT_EQ(algorithms::LinearSearch(v.begin(), v.end(), 1), v.end());
	EXPECT_EQ(algorithms::BinarySearch(v.begin(), v.end(), 1), v.end());
}

}  // namespace
