#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "Sorting.hpp"

namespace
{

class SortingTests : public ::testing::Test
{
protected:
	std::vector<int> unsorted = {5, 3, 8, 1, 2, 7, 4, 6};
	std::vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> empty;
	std::vector<int> single = {42};
};

TEST_F(SortingTests, DISABLED_BubbleSort)
{
	auto v = unsorted;
	algorithms::BubbleSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_SelectionSort)
{
	auto v = unsorted;
	algorithms::SelectionSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_InsertionSort)
{
	auto v = unsorted;
	algorithms::InsertionSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_ShellSort)
{
	auto v = unsorted;
	algorithms::ShellSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_MergeSort)
{
	auto v = unsorted;
	algorithms::MergeSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_QuickSort)
{
	auto v = unsorted;
	algorithms::QuickSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_BucketSort)
{
	auto v = unsorted;
	algorithms::BucketSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_CountingSort)
{
	auto v = unsorted;
	algorithms::CountingSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_RadixSort)
{
	auto v = unsorted;
	algorithms::RadixSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_HeapSort)
{
	auto v = unsorted;
	algorithms::HeapSort(v.begin(), v.end());
	EXPECT_EQ(v, sorted);
}

TEST_F(SortingTests, DISABLED_SortEmptyRange)
{
	auto v = empty;
	algorithms::BubbleSort(v.begin(), v.end());
	EXPECT_TRUE(v.empty());
}

TEST_F(SortingTests, DISABLED_SortSingleElement)
{
	auto v = single;
	algorithms::BubbleSort(v.begin(), v.end());
	EXPECT_EQ(v, single);
}

}  // namespace
