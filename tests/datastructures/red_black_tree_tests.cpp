#include <gtest/gtest.h>

#include "RedBlackTree.hpp"

namespace
{

using datastructures::RedBlackTree;
using IntRBT = RedBlackTree<int>;

TEST(RedBlackTreeTests, NewTreeIsEmpty)
{
	IntRBT tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());
}

TEST(RedBlackTreeTests, DISABLED_InsertSingleElement)
{
	IntRBT tree;
	EXPECT_TRUE(tree.Insert(10));
	EXPECT_FALSE(tree.Empty());
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

TEST(RedBlackTreeTests, DISABLED_InOrderIsSorted)
{
	IntRBT tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(1);
	auto result = tree.InOrder();
	EXPECT_EQ(result, (std::vector<int>{1, 3, 5, 7}));
	EXPECT_TRUE(tree.Validate());
}

TEST(RedBlackTreeTests, DISABLED_EraseExistingKey)
{
	IntRBT tree;
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(15);
	EXPECT_TRUE(tree.Erase(10));
	EXPECT_FALSE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

}  // namespace
