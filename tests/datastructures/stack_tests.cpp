#include <gtest/gtest.h>

#include "Stack.hpp"

namespace
{

using datastructures::ArrayStack;
using datastructures::LinkedListStack;

// ── ArrayStack ─────────────────────────────────────────────────────────

TEST(ArrayStackTests, NewStackIsEmpty)
{
	ArrayStack<int> s;
	EXPECT_TRUE(s.Empty());
	EXPECT_EQ(s.Size(), 0u);
}

TEST(ArrayStackTests, DISABLED_PushAndTop)
{
	ArrayStack<int> s;
	s.Push(10);
	EXPECT_FALSE(s.Empty());
	EXPECT_EQ(s.Size(), 1u);
	EXPECT_EQ(s.Top(), 10);
}

TEST(ArrayStackTests, DISABLED_PopReturnsLastPushed)
{
	ArrayStack<int> s;
	s.Push(1);
	s.Push(2);
	EXPECT_EQ(s.Pop(), 2);
	EXPECT_EQ(s.Pop(), 1);
	EXPECT_TRUE(s.Empty());
}

// ── LinkedListStack ────────────────────────────────────────────────────

TEST(LinkedListStackTests, NewStackIsEmpty)
{
	LinkedListStack<int> s;
	EXPECT_TRUE(s.Empty());
	EXPECT_EQ(s.Size(), 0u);
}

TEST(LinkedListStackTests, DISABLED_PushAndTop)
{
	LinkedListStack<int> s;
	s.Push(42);
	EXPECT_FALSE(s.Empty());
	EXPECT_EQ(s.Size(), 1u);
	EXPECT_EQ(s.Top(), 42);
}

TEST(LinkedListStackTests, DISABLED_PopReturnsLastPushed)
{
	LinkedListStack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	EXPECT_EQ(s.Pop(), 3);
	EXPECT_EQ(s.Pop(), 2);
	EXPECT_EQ(s.Pop(), 1);
	EXPECT_TRUE(s.Empty());
}

}  // namespace
