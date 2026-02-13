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

	Node* GetHead() const { return _head; }
	Node* GetTail() const { return _tail; }

	void PushFront(const T& data)
	{
		Node* newNode = new Node{data, _head, nullptr};
		if (_head)
		{
			_head->prev = newNode;
		}
		else
		{
			_tail = newNode;
		}
		_head = newNode;
	}

	void PushBack(const T& data)
	{
		Node* newNode = new Node{data, nullptr, _tail};
		if (_tail)
		{
			_tail->next = newNode;
		}
		else
		{
			_head = newNode;
		}
		_tail = newNode;
	}

	Node* PopFront()
	{
		if (!_head)
			return nullptr;
		Node* oldHead = _head;
		_head = _head->next;
		if (_head)
		{
			_head->prev = nullptr;
		}
		else
		{
			_tail = nullptr;
		}
		oldHead->next = nullptr;
		oldHead->prev = nullptr;
		return oldHead;
	}

	Node* PopBack()
	{
		if (!_tail)
			return nullptr;
		Node* oldTail = _tail;
		_tail = _tail->prev;
		if (_tail)
		{
			_tail->next = nullptr;
		}
		else
		{
			_head = nullptr;
		}
		oldTail->next = nullptr;
		oldTail->prev = nullptr;
		return oldTail;
	}

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
	Node* _tail = nullptr;
};

template <typename T>
class CircularLinkedList
{
public:
	using Node = datastructures::nodes::DoublyLinkedListNode<T>;

	CircularLinkedList() = default;

	Node* GetHead() const { return _head; }
	Node* GetTail() const { return _tail; }

	void PushFront(const T& data)
	{
		Node* newNode = new Node{data, nullptr, nullptr};
		if (!_head)
		{
			_head = newNode;
			_tail = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
			return;
		}
		newNode->next = _head;
		newNode->prev = _tail;
		_head->prev = newNode;
		_tail->next = newNode;
		_head = newNode;
	}

	void PushBack(const T& data)
	{
		Node* newNode = new Node{data, nullptr, nullptr};
		if (!_tail)
		{
			_head = newNode;
			_tail = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
			return;
		}
		newNode->next = _head;
		newNode->prev = _tail;
		_head->prev = newNode;
		_tail->next = newNode;
		_tail = newNode;
	}

	Node* PopFront()
	{
		if (!_head)
			return nullptr;
		Node* oldHead = _head;
		if (_head == _tail)
		{
			_head = nullptr;
			_tail = nullptr;
			oldHead->next = nullptr;
			oldHead->prev = nullptr;
			return oldHead;
		}
		_head = oldHead->next;
		_head->prev = _tail;
		_tail->next = _head;
		oldHead->next = nullptr;
		oldHead->prev = nullptr;
		return oldHead;
	}

	Node* PopBack()
	{
		if (!_tail)
			return nullptr;
		Node* oldTail = _tail;
		if (_head == _tail)
		{
			_head = nullptr;
			_tail = nullptr;
			oldTail->next = nullptr;
			oldTail->prev = nullptr;
			return oldTail;
		}
		_tail = oldTail->prev;
		_tail->next = _head;
		_head->prev = _tail;
		oldTail->next = nullptr;
		oldTail->prev = nullptr;
		return oldTail;
	}

	~CircularLinkedList()
	{
		if (!_head)
			return;
		Node* current = _head;
		do
		{
			Node* next = current->next;
			delete current;
			current = next;
		} while (current && current != _head);
		_head = nullptr;
		_tail = nullptr;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};
}  // namespace datastructures