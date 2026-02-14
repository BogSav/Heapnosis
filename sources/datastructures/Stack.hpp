#pragma once

#include <cstddef>
#include <cstdlib>
#include <vector>

namespace datastructures
{

/// @brief Stack backed by a dynamic array (std::vector internally).
template <typename T>
class ArrayStack
{
public:
	using value_type = T;

	ArrayStack() = default;
	~ArrayStack() = default;

	/// @brief Push an element onto the top of the stack.
	void Push(const T& /*value*/)
	{
		// TODO: implement
	}

	/// @brief Remove and return the top element.
	T Pop()
	{
		// TODO: implement
		return T{};
	}

	/// @brief Return a reference to the top element without removing it.
	const T& Top() const
	{
		// TODO: implement
		static const T _default{};
		return _default;
	}

	/// @brief Number of elements in the stack.
	std::size_t Size() const { return 0; }

	/// @brief Whether the stack is empty.
	bool Empty() const { return true; }

private:
	std::vector<T> _data;
};

/// @brief Stack backed by a singly-linked list.
template <typename T>
class LinkedListStack
{
public:
	using value_type = T;

	LinkedListStack() = default;

	~LinkedListStack()
	{
		while (_top)
		{
			auto* next = _top->next;
			delete _top;
			_top = next;
		}
	}

	LinkedListStack(const LinkedListStack&) = delete;
	LinkedListStack& operator=(const LinkedListStack&) = delete;
	LinkedListStack(LinkedListStack&&) noexcept = default;
	LinkedListStack& operator=(LinkedListStack&&) noexcept = default;

	/// @brief Push an element onto the top of the stack.
	void Push(const T& /*value*/)
	{
		// TODO: implement
	}

	/// @brief Remove and return the top element.
	T Pop()
	{
		// TODO: implement
		return T{};
	}

	/// @brief Return a reference to the top element without removing it.
	const T& Top() const
	{
		// TODO: implement
		static const T _default{};
		return _default;
	}

	/// @brief Number of elements in the stack.
	std::size_t Size() const { return 0; }

	/// @brief Whether the stack is empty.
	bool Empty() const { return true; }

private:
	struct Node
	{
		T data;
		Node* next = nullptr;
	};
	Node* _top = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
