#include <gtest/gtest.h>

#include "BinomialQueue.hpp"

namespace
{

using datastructures::BinomialQueue;

TEST(BinomialQueueTests, NewQueueIsEmpty)
{
	BinomialQueue<int> queue;
	EXPECT_TRUE(queue.Empty());
	EXPECT_EQ(queue.Size(), 0u);
}

TEST(BinomialQueueTests, DISABLED_PushAndTop)
{
	BinomialQueue<int> queue;
	queue.Push(5);
	queue.Push(3);
	queue.Push(7);
	EXPECT_EQ(queue.Top(), 3);
	EXPECT_EQ(queue.Size(), 3u);
}

TEST(BinomialQueueTests, DISABLED_MergeTwoQueues)
{
	BinomialQueue<int> q1;
	BinomialQueue<int> q2;
	q1.Push(5);
	q2.Push(3);
	q1.Merge(q2);
	EXPECT_EQ(q1.Top(), 3);
	EXPECT_EQ(q1.Size(), 2u);
}

}  // namespace
