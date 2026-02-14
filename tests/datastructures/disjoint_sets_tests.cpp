#include <gtest/gtest.h>

#include "DisjointSets.hpp"

namespace
{

using datastructures::DisjointSets;

TEST(DisjointSetsTests, NewSetIsEmpty)
{
	DisjointSets<int> ds;
	EXPECT_EQ(ds.Size(), 0u);
}

TEST(DisjointSetsTests, DISABLED_MakeSetAndFind)
{
	DisjointSets<int> ds;
	ds.MakeSet(1);
	ds.MakeSet(2);
	EXPECT_EQ(ds.Size(), 2u);
	EXPECT_EQ(ds.Find(1), 1);
	EXPECT_EQ(ds.Find(2), 2);
	EXPECT_FALSE(ds.Connected(1, 2));
}

TEST(DisjointSetsTests, DISABLED_UnionAndConnected)
{
	DisjointSets<int> ds;
	ds.MakeSet(1);
	ds.MakeSet(2);
	ds.MakeSet(3);
	ds.Union(1, 2);
	EXPECT_TRUE(ds.Connected(1, 2));
	EXPECT_FALSE(ds.Connected(1, 3));
	ds.Union(2, 3);
	EXPECT_TRUE(ds.Connected(1, 3));
}

}  // namespace
