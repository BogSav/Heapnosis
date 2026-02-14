#include <gtest/gtest.h>

#include "ClosedHashTableBucket.hpp"

namespace
{

using datastructures::ClosedHashTableBucket;

TEST(ClosedHashTableBucketTests, NewTableIsEmpty)
{
	ClosedHashTableBucket<int, int> table;
	EXPECT_TRUE(table.Empty());
	EXPECT_EQ(table.Size(), 0u);
}

TEST(ClosedHashTableBucketTests, DISABLED_InsertAndFind)
{
	ClosedHashTableBucket<int, int> table;
	table.Insert(1, 100);
	EXPECT_FALSE(table.Empty());
	EXPECT_EQ(table.Size(), 1u);
	EXPECT_TRUE(table.Contains(1));
	auto val = table.Find(1);
	ASSERT_TRUE(val.has_value());
	EXPECT_EQ(val.value(), 100);
}

TEST(ClosedHashTableBucketTests, DISABLED_EraseKey)
{
	ClosedHashTableBucket<int, int> table;
	table.Insert(1, 100);
	EXPECT_TRUE(table.Erase(1));
	EXPECT_FALSE(table.Contains(1));
	EXPECT_TRUE(table.Empty());
}

}  // namespace
