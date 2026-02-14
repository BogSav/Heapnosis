#include <gtest/gtest.h>

#include "BTree.hpp"

namespace
{

using datastructures::BTree;
using IntBTree = BTree<int, 4>;

TEST(BTreeTests, NewTreeIsEmpty)
{
	IntBTree tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());
}

TEST(BTreeTests, DISABLED_InsertSingleElement)
{
	IntBTree tree;
	tree.Insert(10);
	EXPECT_FALSE(tree.Empty());
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

TEST(BTreeTests, DISABLED_InOrderIsSorted)
{
	IntBTree tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(1);
	tree.Insert(4);
	auto result = tree.InOrder();
	EXPECT_EQ(result, (std::vector<int>{1, 3, 4, 5, 7}));
	EXPECT_TRUE(tree.Validate());
}

TEST(BTreeTests, DISABLED_EraseExistingKey)
{
	IntBTree tree;
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(15);
	EXPECT_TRUE(tree.Erase(10));
	EXPECT_FALSE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

}  // namespace
