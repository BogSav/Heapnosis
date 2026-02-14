#include <gtest/gtest.h>

#include "TernarySearchTree.hpp"

namespace
{

using datastructures::TernarySearchTree;

TEST(TernarySearchTreeTests, NewTreeIsEmpty)
{
	TernarySearchTree tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
}

TEST(TernarySearchTreeTests, DISABLED_InsertAndSearch)
{
	TernarySearchTree tree;
	tree.Insert("cat");
	tree.Insert("car");
	EXPECT_TRUE(tree.Search("cat"));
	EXPECT_TRUE(tree.Search("car"));
	EXPECT_FALSE(tree.Search("ca"));
	EXPECT_TRUE(tree.StartsWith("ca"));
}

TEST(TernarySearchTreeTests, DISABLED_EraseWord)
{
	TernarySearchTree tree;
	tree.Insert("bug");
	EXPECT_TRUE(tree.Erase("bug"));
	EXPECT_FALSE(tree.Search("bug"));
	EXPECT_TRUE(tree.Empty());
}

}  // namespace
