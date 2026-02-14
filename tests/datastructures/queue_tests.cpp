#include <gtest/gtest.h>

#include "Queue.hpp"

namespace
{

using datastructures::ArrayQueue;
using datastructures::LinkedListQueue;

// ── ArrayQueue ─────────────────────────────────────────────────────────

TEST(ArrayQueueTests, NewQueueIsEmpty)
{
	ArrayQueue<int> q;
	EXPECT_TRUE(q.Empty());
	EXPECT_EQ(q.Size(), 0u);
}

TEST(ArrayQueueTests, DISABLED_EnqueueAndFront)
{
	ArrayQueue<int> q;
	q.Enqueue(10);
	EXPECT_FALSE(q.Empty());
	EXPECT_EQ(q.Size(), 1u);
	EXPECT_EQ(q.Front(), 10);
}

TEST(ArrayQueueTests, DISABLED_DequeueFIFO)
{
	ArrayQueue<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	EXPECT_EQ(q.Dequeue(), 1);
	EXPECT_EQ(q.Dequeue(), 2);
	EXPECT_EQ(q.Dequeue(), 3);
	EXPECT_TRUE(q.Empty());
}

// ── LinkedListQueue ────────────────────────────────────────────────────

TEST(LinkedListQueueTests, NewQueueIsEmpty)
{
	LinkedListQueue<int> q;
	EXPECT_TRUE(q.Empty());
	EXPECT_EQ(q.Size(), 0u);
}

TEST(LinkedListQueueTests, DISABLED_EnqueueAndFront)
{
	LinkedListQueue<int> q;
	q.Enqueue(42);
	EXPECT_FALSE(q.Empty());
	EXPECT_EQ(q.Size(), 1u);
	EXPECT_EQ(q.Front(), 42);
}

TEST(LinkedListQueueTests, DISABLED_DequeueFIFO)
{
	LinkedListQueue<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	EXPECT_EQ(q.Dequeue(), 1);
	EXPECT_EQ(q.Dequeue(), 2);
	EXPECT_EQ(q.Dequeue(), 3);
	EXPECT_TRUE(q.Empty());
}

}  // namespace
