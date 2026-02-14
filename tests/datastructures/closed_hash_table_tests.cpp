#include <gtest/gtest.h>

#include "ClosedHashTable.hpp"

namespace
{

using datastructures::ClosedHashTable;

TEST(ClosedHashTableTests, NewTableIsEmpty)
{
	ClosedHashTable<int, int> table;
	EXPECT_TRUE(table.Empty());
	EXPECT_EQ(table.Size(), 0u);
}

TEST(ClosedHashTableTests, DISABLED_InsertAndFind)
{
	ClosedHashTable<int, int> table;
	table.Insert(1, 100);
	EXPECT_FALSE(table.Empty());
	EXPECT_EQ(table.Size(), 1u);
	EXPECT_TRUE(table.Contains(1));
	auto val = table.Find(1);
	ASSERT_TRUE(val.has_value());
	EXPECT_EQ(val.value(), 100);
}

TEST(ClosedHashTableTests, DISABLED_EraseKey)
{
	ClosedHashTable<int, int> table;
	table.Insert(1, 100);
	EXPECT_TRUE(table.Erase(1));
	EXPECT_FALSE(table.Contains(1));
	EXPECT_TRUE(table.Empty());
}

}  // namespace
