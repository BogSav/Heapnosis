#include <gtest/gtest.h>

#include "BinarySearchTree.hpp"

namespace
{

using datastructures::BinarySearchTree;
using IntBST = BinarySearchTree<int>;

TEST(BinarySearchTreeTests, NewTreeIsEmpty)
{
	IntBST tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_EQ(tree.Height(), 0);
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());
}

TEST(BinarySearchTreeTests, DISABLED_InsertSingleElement)
{
	IntBST tree;
	EXPECT_TRUE(tree.Insert(10));
	EXPECT_FALSE(tree.Empty());
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

TEST(BinarySearchTreeTests, DISABLED_InOrderIsSorted)
{
	IntBST tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(1);
	tree.Insert(4);
	auto result = tree.InOrder();
	EXPECT_EQ(result, (std::vector<int>{1, 3, 4, 5, 7}));
	EXPECT_TRUE(tree.Validate());
}

TEST(BinarySearchTreeTests, DISABLED_EraseExistingKey)
{
	IntBST tree;
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(15);
	EXPECT_TRUE(tree.Erase(10));
	EXPECT_FALSE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

}  // namespace
