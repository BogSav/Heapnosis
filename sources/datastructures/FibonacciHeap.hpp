#pragma once

#include <cstddef>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Fibonacci Heap — lazily-merged priority queue with amortized O(1) insert / decrease-key.
template <typename T>
class FibonacciHeap
{
public:
	using value_type = T;
	using Node = nodes::FibonacciNode<T>;

	FibonacciHeap() = default;
	~FibonacciHeap() = default;

	FibonacciHeap(const FibonacciHeap&) = delete;
	FibonacciHeap& operator=(const FibonacciHeap&) = delete;
	FibonacciHeap(FibonacciHeap&&) noexcept = default;
	FibonacciHeap& operator=(FibonacciHeap&&) noexcept = default;

	/// @brief Insert an element (O(1) amortized).
	/// @return Pointer to the inserted node (for use with DecreaseKey).
	Node* Push(const T& /*value*/)
	{
		// TODO: implement — add to root list, update min
		return nullptr;
	}

	/// @brief Remove the minimum element (O(log n) amortized).
	void Pop()
	{
		// TODO: implement — extract min, consolidate
	}

	/// @brief Return the minimum element.
	const T& Top() const
	{
		// TODO: handle empty case
		static const T _default{};
		if (!_min)
			return _default;
		return _min->key;
	}

	/// @brief Decrease the key of a node (O(1) amortized).
	void DecreaseKey(Node* /*node*/, const T& /*newKey*/)
	{
		// TODO: implement — cut, cascading cut
	}

	/// @brief Merge another Fibonacci heap into this one (O(1)).
	void Merge(FibonacciHeap& /*other*/)
	{
		// TODO: implement — concatenate root lists
	}

	/// @brief Number of elements.
	std::size_t Size() const { return _size; }

	/// @brief Whether the heap is empty.
	bool Empty() const { return _size == 0; }

private:
	Node* _min = nullptr; // pointer to minimum root
	std::size_t _size = 0;
};

}  // namespace datastructures
