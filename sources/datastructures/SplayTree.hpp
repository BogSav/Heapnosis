#pragma once

#include <cstddef>
#include <vector>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Splay Tree — self-adjusting BST (recently accessed elements near root).
template <typename T>
class SplayTree
{
public:
	using value_type = T;
	using Node = nodes::SplayTreeNode<T>;

	SplayTree() = default;
	~SplayTree() = default;

	SplayTree(const SplayTree&) = delete;
	SplayTree& operator=(const SplayTree&) = delete;
	SplayTree(SplayTree&&) noexcept = default;
	SplayTree& operator=(SplayTree&&) noexcept = default;

	/// @brief Insert a key (then splay it to root).
	/// @return true if new, false if duplicate.
	bool Insert(const T& /*value*/) { return false; }

	/// @brief Erase a key.
	/// @return true if found and removed.
	bool Erase(const T& /*value*/) { return false; }

	/// @brief Search for a key (splays it to root if found).
	bool Contains(const T& /*value*/) { return false; }

	/// @brief Number of elements.
	std::size_t Size() const { return 0; }

	/// @brief Whether tree is empty.
	bool Empty() const { return true; }

	/// @brief In-order traversal (sorted).
	std::vector<T> InOrder() const { return {}; }

	/// @brief Validate BST property.
	bool Validate() const { return true; }

private:
	/// @brief Splay node x to the root.
	void Splay(Node* /*x*/)
	{
		// TODO: implement zig, zig-zig, zig-zag rotations
	}

	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
