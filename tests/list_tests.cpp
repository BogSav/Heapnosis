#include <gtest/gtest.h>

#include "List.hpp"

namespace
{
using datastructures::CircularLinkedList;
using datastructures::DoublyLinkedList;
using datastructures::ForwardList;

using ForwardNode = datastructures::nodes::ForwardListNode<int>;
using DoubleNode = datastructures::nodes::DoublyLinkedListNode<int>;

TEST(ForwardListTests, PushFrontUpdatesHead)
{
	ForwardList<int> list;

	list.PushFront(10);
	list.PushFront(20);

	ForwardNode* head = list.GetHead();
	ASSERT_NE(head, nullptr);
	EXPECT_EQ(head->data, 20);
	ASSERT_NE(head->next, nullptr);
	EXPECT_EQ(head->next->data, 10);
}

TEST(ForwardListTests, PushBackUpdatesTail)
{
	ForwardList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	ForwardNode* tail = list.GetTail();
	ASSERT_NE(tail, nullptr);
	EXPECT_EQ(tail->data, 3);
	EXPECT_EQ(tail->next, nullptr);
}

TEST(ForwardListTests, PopFrontReturnsHead)
{
	ForwardList<int> list;
	list.PushBack(5);
	list.PushBack(6);

	ForwardNode* popped = list.PopFront();
	ASSERT_NE(popped, nullptr);
	EXPECT_EQ(popped->data, 5);
	delete popped;

	ForwardNode* head = list.GetHead();
	ASSERT_NE(head, nullptr);
	EXPECT_EQ(head->data, 6);
}

TEST(ForwardListTests, PopBackReturnsTail)
{
	ForwardList<int> list;
	list.PushBack(7);
	list.PushBack(8);

	ForwardNode* popped = list.PopBack();
	ASSERT_NE(popped, nullptr);
	EXPECT_EQ(popped->data, 8);
	delete popped;

	ForwardNode* tail = list.GetTail();
	ASSERT_NE(tail, nullptr);
	EXPECT_EQ(tail->data, 7);
}

TEST(DoublyLinkedListTests, PushFrontAndPushBackMaintainLinks)
{
	DoublyLinkedList<int> list;

	list.PushFront(2);
	list.PushFront(1);
	list.PushBack(3);

	DoubleNode* head = list.GetHead();
	DoubleNode* tail = list.GetTail();
	ASSERT_NE(head, nullptr);
	ASSERT_NE(tail, nullptr);

	EXPECT_EQ(head->data, 1);
	EXPECT_EQ(tail->data, 3);

	ASSERT_NE(head->next, nullptr);
	EXPECT_EQ(head->next->data, 2);
	EXPECT_EQ(head->prev, nullptr);

	ASSERT_NE(tail->prev, nullptr);
	EXPECT_EQ(tail->prev->data, 2);
	EXPECT_EQ(tail->next, nullptr);

	EXPECT_EQ(head->next->prev, head);
	EXPECT_EQ(tail->prev->next, tail);
}

TEST(DoublyLinkedListTests, PopFrontAndPopBackReturnNodes)
{
	DoublyLinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	DoubleNode* front = list.PopFront();
	ASSERT_NE(front, nullptr);
	EXPECT_EQ(front->data, 1);
	delete front;

	DoubleNode* back = list.PopBack();
	ASSERT_NE(back, nullptr);
	EXPECT_EQ(back->data, 3);
	delete back;

	DoubleNode* head = list.GetHead();
	DoubleNode* tail = list.GetTail();
	ASSERT_NE(head, nullptr);
	ASSERT_NE(tail, nullptr);
	EXPECT_EQ(head->data, 2);
	EXPECT_EQ(tail->data, 2);
}

TEST(CircularLinkedListTests, PushBackCreatesCircularLinks)
{
	CircularLinkedList<int> list;
	list.PushBack(1);

	DoubleNode* head = list.GetHead();
	DoubleNode* tail = list.GetTail();
	ASSERT_NE(head, nullptr);
	ASSERT_NE(tail, nullptr);
	EXPECT_EQ(head, tail);
	EXPECT_EQ(head->next, head);
	EXPECT_EQ(head->prev, head);
}

TEST(CircularLinkedListTests, PushFrontAndPushBackKeepCircleConsistent)
{
	CircularLinkedList<int> list;
	list.PushBack(2);
	list.PushFront(1);
	list.PushBack(3);

	DoubleNode* head = list.GetHead();
	DoubleNode* tail = list.GetTail();
	ASSERT_NE(head, nullptr);
	ASSERT_NE(tail, nullptr);

	EXPECT_EQ(head->data, 1);
	EXPECT_EQ(tail->data, 3);
	EXPECT_EQ(tail->next, head);
	EXPECT_EQ(head->prev, tail);

	ASSERT_NE(head->next, nullptr);
	EXPECT_EQ(head->next->data, 2);
	EXPECT_EQ(head->next->prev, head);
}

TEST(CircularLinkedListTests, PopFrontAndPopBackUpdateHeadAndTail)
{
	CircularLinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	DoubleNode* front = list.PopFront();
	ASSERT_NE(front, nullptr);
	EXPECT_EQ(front->data, 1);
	delete front;

	DoubleNode* back = list.PopBack();
	ASSERT_NE(back, nullptr);
	EXPECT_EQ(back->data, 3);
	delete back;

	DoubleNode* head = list.GetHead();
	DoubleNode* tail = list.GetTail();
	ASSERT_NE(head, nullptr);
	ASSERT_NE(tail, nullptr);
	EXPECT_EQ(head->data, 2);
	EXPECT_EQ(tail->data, 2);
	EXPECT_EQ(head, tail);
	EXPECT_EQ(head->next, head);
	EXPECT_EQ(head->prev, head);
}
}  // namespace
