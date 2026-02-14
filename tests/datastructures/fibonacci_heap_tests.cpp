#include <gtest/gtest.h>

#include "FibonacciHeap.hpp"

namespace
{

using datastructures::FibonacciHeap;

TEST(FibonacciHeapTests, NewHeapIsEmpty)
{
	FibonacciHeap<int> heap;
	EXPECT_TRUE(heap.Empty());
	EXPECT_EQ(heap.Size(), 0u);
}

TEST(FibonacciHeapTests, DISABLED_PushAndTop)
{
	FibonacciHeap<int> heap;
	heap.Push(5);
	heap.Push(3);
	heap.Push(7);
	EXPECT_EQ(heap.Top(), 3);
	EXPECT_EQ(heap.Size(), 3u);
}

TEST(FibonacciHeapTests, DISABLED_PopRemovesMin)
{
	FibonacciHeap<int> heap;
	heap.Push(5);
	heap.Push(3);
	heap.Push(7);
	heap.Pop();
	EXPECT_EQ(heap.Top(), 5);
	EXPECT_EQ(heap.Size(), 2u);
}

TEST(FibonacciHeapTests, DISABLED_DecreaseKey)
{
	FibonacciHeap<int> heap;
	auto* node = heap.Push(10);
	heap.Push(5);
	heap.DecreaseKey(node, 2);
	EXPECT_EQ(heap.Top(), 2);
}

}  // namespace
