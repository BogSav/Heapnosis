#include <gtest/gtest.h>

#include "BPlusTree.hpp"

namespace
{

using datastructures::BPlusTree;
using IntBPlusTree = BPlusTree<int, 4>;

TEST(BPlusTreeTests, NewTreeIsEmpty)
{
	IntBPlusTree tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());
}

TEST(BPlusTreeTests, DISABLED_InsertSingleElement)
{
	IntBPlusTree tree;
	tree.Insert(10);
	EXPECT_FALSE(tree.Empty());
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

TEST(BPlusTreeTests, DISABLED_RangeQuery)
{
	IntBPlusTree tree;
	for (int i = 1; i <= 10; ++i)
		tree.Insert(i);

	auto range = tree.RangeQuery(3, 7);
	EXPECT_EQ(range, (std::vector<int>{3, 4, 5, 6, 7}));
}

}  // namespace
