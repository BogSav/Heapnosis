#include <gtest/gtest.h>

#include "OpenHashTable.hpp"

namespace
{

using datastructures::OpenHashTable;

TEST(OpenHashTableTests, NewTableIsEmpty)
{
	OpenHashTable<int, int> table;
	EXPECT_TRUE(table.Empty());
	EXPECT_EQ(table.Size(), 0u);
}

TEST(OpenHashTableTests, DISABLED_InsertAndFind)
{
	OpenHashTable<int, int> table;
	table.Insert(1, 100);
	EXPECT_FALSE(table.Empty());
	EXPECT_EQ(table.Size(), 1u);
	EXPECT_TRUE(table.Contains(1));
	auto val = table.Find(1);
	ASSERT_TRUE(val.has_value());
	EXPECT_EQ(val.value(), 100);
}

TEST(OpenHashTableTests, DISABLED_EraseKey)
{
	OpenHashTable<int, int> table;
	table.Insert(1, 100);
	EXPECT_TRUE(table.Erase(1));
	EXPECT_FALSE(table.Contains(1));
	EXPECT_TRUE(table.Empty());
}

}  // namespace
