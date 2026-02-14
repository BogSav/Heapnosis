#include <gtest/gtest.h>

#include "BinaryHeap.hpp"

namespace
{

using datastructures::BinaryHeap;

TEST(BinaryHeapTests, NewHeapIsEmpty)
{
	BinaryHeap<int> heap;
	EXPECT_TRUE(heap.Empty());
	EXPECT_EQ(heap.Size(), 0u);
}

TEST(BinaryHeapTests, DISABLED_PushAndTop)
{
	BinaryHeap<int> heap;
	heap.Push(5);
	heap.Push(3);
	heap.Push(7);
	EXPECT_EQ(heap.Top(), 3); // min-heap
	EXPECT_EQ(heap.Size(), 3u);
	EXPECT_TRUE(heap.Validate());
}

TEST(BinaryHeapTests, DISABLED_PopRemovesMin)
{
	BinaryHeap<int> heap;
	heap.Push(5);
	heap.Push(3);
	heap.Push(7);
	heap.Pop();
	EXPECT_EQ(heap.Top(), 5);
	EXPECT_EQ(heap.Size(), 2u);
	EXPECT_TRUE(heap.Validate());
}

}  // namespace
