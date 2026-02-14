#include <gtest/gtest.h>

#include "Trie.hpp"

namespace
{

using datastructures::Trie;

TEST(TrieTests, NewTrieIsEmpty)
{
	Trie trie;
	EXPECT_TRUE(trie.Empty());
	EXPECT_EQ(trie.Size(), 0u);
}

TEST(TrieTests, DISABLED_InsertAndSearch)
{
	Trie trie;
	trie.Insert("hello");
	EXPECT_TRUE(trie.Search("hello"));
	EXPECT_FALSE(trie.Search("hell"));
	EXPECT_TRUE(trie.StartsWith("hell"));
	EXPECT_EQ(trie.Size(), 1u);
}

TEST(TrieTests, DISABLED_EraseWord)
{
	Trie trie;
	trie.Insert("hello");
	trie.Insert("help");
	EXPECT_TRUE(trie.Erase("hello"));
	EXPECT_FALSE(trie.Search("hello"));
	EXPECT_TRUE(trie.Search("help"));
}

}  // namespace
