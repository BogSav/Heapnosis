#pragma once

#include <cstddef>
#include <cstdlib>
#include <vector>

namespace datastructures
{

/// @brief Queue backed by a dynamic array (circular buffer style).
template <typename T>
class ArrayQueue
{
public:
	using value_type = T;

	ArrayQueue() = default;
	~ArrayQueue() = default;

	/// @brief Add an element to the back of the queue.
	void Enqueue(const T& /*value*/)
	{
		// TODO: implement
	}

	/// @brief Remove and return the front element.
	T Dequeue()
	{
		// TODO: implement
		return T{};
	}

	/// @brief Return a reference to the front element without removing it.
	const T& Front() const
	{
		// TODO: implement
		static const T _default{};
		return _default;
	}

	/// @brief Number of elements in the queue.
	std::size_t Size() const { return 0; }

	/// @brief Whether the queue is empty.
	bool Empty() const { return true; }

private:
	std::vector<T> _data;
	std::size_t _head = 0;
	std::size_t _tail = 0;
	std::size_t _size = 0;
};

/// @brief Queue backed by a singly-linked list.
template <typename T>
class LinkedListQueue
{
public:
	using value_type = T;

	LinkedListQueue() = default;

	~LinkedListQueue()
	{
		while (_head)
		{
			auto* next = _head->next;
			delete _head;
			_head = next;
		}
	}

	LinkedListQueue(const LinkedListQueue&) = delete;
	LinkedListQueue& operator=(const LinkedListQueue&) = delete;
	LinkedListQueue(LinkedListQueue&&) noexcept = default;
	LinkedListQueue& operator=(LinkedListQueue&&) noexcept = default;

	/// @brief Add an element to the back of the queue.
	void Enqueue(const T& /*value*/)
	{
		// TODO: implement
	}

	/// @brief Remove and return the front element.
	T Dequeue()
	{
		// TODO: implement
		return T{};
	}

	/// @brief Return a reference to the front element without removing it.
	const T& Front() const
	{
		// TODO: implement
		static const T _default{};
		return _default;
	}

	/// @brief Number of elements in the queue.
	std::size_t Size() const { return 0; }

	/// @brief Whether the queue is empty.
	bool Empty() const { return true; }

private:
	struct Node
	{
		T data;
		Node* next = nullptr;
	};
	Node* _head = nullptr;
	Node* _tail = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
