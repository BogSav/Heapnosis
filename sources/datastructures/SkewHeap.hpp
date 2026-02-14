#pragma once

#include <cstddef>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Skew Heap — self-adjusting mergeable heap (no rank tracking).
template <typename T>
class SkewHeap
{
public:
	using value_type = T;
	using Node = nodes::SkewNode<T>;

	SkewHeap() = default;
	~SkewHeap() = default;

	SkewHeap(const SkewHeap&) = delete;
	SkewHeap& operator=(const SkewHeap&) = delete;
	SkewHeap(SkewHeap&&) noexcept = default;
	SkewHeap& operator=(SkewHeap&&) noexcept = default;

	/// @brief Insert an element.
	void Push(const T& /*value*/)
	{
		// TODO: implement — create single node, merge
	}

	/// @brief Remove the minimum element.
	void Pop()
	{
		// TODO: implement — merge left and right subtrees
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

	/// @brief Merge another skew heap into this one.
	void Merge(SkewHeap& /*other*/)
	{
		// TODO: implement
	}

	/// @brief Number of elements.
	std::size_t Size() const { return _size; }

	/// @brief Whether the heap is empty.
	bool Empty() const { return _size == 0; }

private:
	/// @brief Recursive merge with unconditional swap.
	Node* MergeNodes(Node* /*h1*/, Node* /*h2*/)
	{
		// TODO: implement
		return nullptr;
	}

	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
