#include <gtest/gtest.h>

#include "RadixTree.hpp"

namespace
{

using datastructures::RadixTree;

TEST(RadixTreeTests, NewTreeIsEmpty)
{
	RadixTree tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
}

TEST(RadixTreeTests, DISABLED_InsertAndSearch)
{
	RadixTree tree;
	tree.Insert("hello");
	tree.Insert("help");
	EXPECT_TRUE(tree.Search("hello"));
	EXPECT_TRUE(tree.Search("help"));
	EXPECT_FALSE(tree.Search("hel"));
	EXPECT_TRUE(tree.StartsWith("hel"));
}

TEST(RadixTreeTests, DISABLED_EraseWord)
{
	RadixTree tree;
	tree.Insert("test");
	EXPECT_TRUE(tree.Erase("test"));
	EXPECT_FALSE(tree.Search("test"));
	EXPECT_TRUE(tree.Empty());
}

}  // namespace
