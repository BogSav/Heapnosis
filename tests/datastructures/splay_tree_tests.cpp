#include <gtest/gtest.h>

#include "SplayTree.hpp"

namespace
{

using datastructures::SplayTree;
using IntSplay = SplayTree<int>;

TEST(SplayTreeTests, NewTreeIsEmpty)
{
	IntSplay tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());
}

TEST(SplayTreeTests, DISABLED_InsertSingleElement)
{
	IntSplay tree;
	EXPECT_TRUE(tree.Insert(10));
	EXPECT_FALSE(tree.Empty());
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(10));
	EXPECT_TRUE(tree.Validate());
}

TEST(SplayTreeTests, DISABLED_InOrderIsSorted)
{
	IntSplay tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(1);
	auto result = tree.InOrder();
	EXPECT_EQ(result, (std::vector<int>{1, 3, 5, 7}));
	EXPECT_TRUE(tree.Validate());
}

}  // namespace
