#pragma once

#include "Nodes.hpp"

namespace datastructures
{
template <typename T>
class ForwardList
{
public:
	using Node = datastructures::nodes::ForwardListNode<T>;

	ForwardList() = default;

	Node* GetHead() const { return _head; }

	/// @brief Returns the last node in the list. This operation runs in O(n) time
	/// since we are working on a singly linked list.
	/// @return Pointer to the last node, or nullptr if the list is empty
	Node* GetTail() const
	{
		Node* current = _head;
		if (!current)
			return nullptr;
		while (current->next)
		{
			current = current->next;
		}
		return current;
	}

	void PushFront(const T& data)
	{
		Node* newNode = new Node{data, _head};
		_head = newNode;
	}
	void PushBack(const T& data)
	{
		Node* newNode = new Node{data, nullptr};
		if (!_head)
		{
			_head = newNode;
			return;
		}
		Node* tail = GetTail();
		tail->next = newNode;
	}

	Node* PopFront()
	{
		if (_head)
		{
			Node* oldHead = _head;
			_head = _head->next;
			return oldHead;
		}
		return nullptr;
	}
	Node* PopBack()
	{
		if (!_head)
			return nullptr;
		if (!_head->next)
		{
			Node* oldHead = _head;
			_head = nullptr;
			return oldHead;
		}
		Node* current = _head;
		while (current->next && current->next->next)
		{
			current = current->next;
		}
		Node* oldTail = current->next;
		current->next = nullptr;
		return oldTail;
	}

	~ForwardList()
	{
		Node* current = _head;
		while (current)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

private:
	Node* _head = nullptr;
};

template <typename T>
class DoublyLinkedList
{
public:
	using Node = datastructures::nodes::DoublyLinkedListNode<T>;

	DoublyLinkedList() = default;
	~DoublyLinkedList()
	{
		Node* current = _head;
		while (current)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

private:
	Node* _head = nullptr;
	Node* tail = nullptr;
};

template <typename T>
class CircularLinkedList
{
public:
	using Node = datastructures::nodes::DoublyLinkedListNode<T>;

private:
	Node* _head = nullptr;
	Node* tail = nullptr;
};
}  // namespace datastructures