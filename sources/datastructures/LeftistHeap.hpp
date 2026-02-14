#pragma once

#include <cstddef>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Leftist Heap — mergeable min-heap biased to the left.
template <typename T>
class LeftistHeap
{
public:
	using value_type = T;
	using Node = nodes::LeftistNode<T>;

	LeftistHeap() = default;
	~LeftistHeap() = default;

	LeftistHeap(const LeftistHeap&) = delete;
	LeftistHeap& operator=(const LeftistHeap&) = delete;
	LeftistHeap(LeftistHeap&&) noexcept = default;
	LeftistHeap& operator=(LeftistHeap&&) noexcept = default;

	/// @brief Insert an element.
	void Push(const T& /*value*/)
	{
		// TODO: implement — create single node, merge
	}

	/// @brief Remove the minimum element.
	void Pop()
	{
		// TODO: implement — merge left and right subtrees of root
	}

	/// @brief Return the minimum element.
	const T& Top() const
	{
		// TODO: handle empty case
		static const T _default{};
		if (!_root)
			return _default;
		return _root->key;
	}

	/// @brief Merge another leftist heap into this one.
	void Merge(LeftistHeap& /*other*/)
	{
		// TODO: implement
	}

	/// @brief Number of elements.
	std::size_t Size() const { return _size; }

	/// @brief Whether the heap is empty.
	bool Empty() const { return _size == 0; }

private:
	/// @brief Recursive merge of two leftist trees.
	Node* MergeNodes(Node* /*h1*/, Node* /*h2*/)
	{
		// TODO: implement
		return nullptr;
	}

	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
