#include <gtest/gtest.h>

#include "SkewHeap.hpp"

namespace
{

using datastructures::SkewHeap;

TEST(SkewHeapTests, NewHeapIsEmpty)
{
	SkewHeap<int> heap;
	EXPECT_TRUE(heap.Empty());
	EXPECT_EQ(heap.Size(), 0u);
}

TEST(SkewHeapTests, DISABLED_PushAndTop)
{
	SkewHeap<int> heap;
	heap.Push(5);
	heap.Push(3);
	heap.Push(7);
	EXPECT_EQ(heap.Top(), 3);
	EXPECT_EQ(heap.Size(), 3u);
}

TEST(SkewHeapTests, DISABLED_MergeTwoHeaps)
{
	SkewHeap<int> h1;
	SkewHeap<int> h2;
	h1.Push(5);
	h2.Push(3);
	h1.Merge(h2);
	EXPECT_EQ(h1.Top(), 3);
	EXPECT_EQ(h1.Size(), 2u);
}

}  // namespace
