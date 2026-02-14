#pragma once

#include <cstddef>
#include <functional>
#include <vector>

namespace datastructures
{

/// @brief Binary Min-Heap backed by a dynamic array.
/// @tparam T Value type.
/// @tparam Compare Comparator (default std::less → min-heap).
template <typename T, typename Compare = std::less<T>>
class BinaryHeap
{
public:
	using value_type = T;

	BinaryHeap() = default;
	~BinaryHeap() = default;

	/// @brief Insert an element.
	void Push(const T& /*value*/)
	{
		// TODO: implement — append + bubble-up
	}

	/// @brief Remove the top (min/max) element.
	void Pop()
	{
		// TODO: implement — swap root with last, remove, sift-down
	}

	/// @brief Return the top element without removing it.
	const T& Top() const
	{
		// TODO: handle empty case
		static const T _default{};
		if (_data.empty())
			return _default;
		return _data.front();
	}

	/// @brief Number of elements.
	std::size_t Size() const { return _data.size(); }

	/// @brief Whether the heap is empty.
	bool Empty() const { return _data.empty(); }

	/// @brief Validate the heap property.
	bool Validate() const { return true; }

private:
	std::vector<T> _data;
	Compare _cmp;
};

}  // namespace datastructures
