#pragma once

#include <cstddef>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Binomial Queue (mergeable priority queue).
template <typename T>
class BinomialQueue
{
public:
	using value_type = T;
	using Node = nodes::BinomialNode<T>;

	BinomialQueue() = default;
	~BinomialQueue() = default;

	BinomialQueue(const BinomialQueue&) = delete;
	BinomialQueue& operator=(const BinomialQueue&) = delete;
	BinomialQueue(BinomialQueue&&) noexcept = default;
	BinomialQueue& operator=(BinomialQueue&&) noexcept = default;

	/// @brief Insert an element.
	void Push(const T& /*value*/)
	{
		// TODO: implement — create single-node tree, merge
	}

	/// @brief Remove the minimum element.
	void Pop()
	{
		// TODO: implement — find min root, remove, merge children back
	}

	/// @brief Return the minimum element.
	const T& Top() const
	{
		// TODO: implement — scan root list
		static const T _default{};
		return _default;
	}

	/// @brief Merge another binomial queue into this one.
	void Merge(BinomialQueue& /*other*/)
	{
		// TODO: implement
	}

	/// @brief Number of elements.
	std::size_t Size() const { return _size; }

	/// @brief Whether the queue is empty.
	bool Empty() const { return _size == 0; }

private:
	Node* _head = nullptr; // head of root list
	std::size_t _size = 0;
};

}  // namespace datastructures
