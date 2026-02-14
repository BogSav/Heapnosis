#pragma once

#include <cstddef>
#include <vector>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Red-Black Tree — self-balancing BST with color invariants.
template <typename T>
class RedBlackTree
{
public:
	using value_type = T;
	using Node = nodes::RedBlackTreeNode<T>;

	RedBlackTree() = default;
	~RedBlackTree() = default;

	RedBlackTree(const RedBlackTree&) = delete;
	RedBlackTree& operator=(const RedBlackTree&) = delete;
	RedBlackTree(RedBlackTree&&) noexcept = default;
	RedBlackTree& operator=(RedBlackTree&&) noexcept = default;

	/// @brief Insert a key.
	/// @return true if new node, false if duplicate.
	bool Insert(const T& /*value*/) { return false; }

	/// @brief Erase a key.
	/// @return true if found and removed.
	bool Erase(const T& /*value*/) { return false; }

	/// @brief Check existence.
	bool Contains(const T& /*value*/) const { return false; }

	/// @brief Number of elements.
	std::size_t Size() const { return 0; }

	/// @brief Whether tree is empty.
	bool Empty() const { return true; }

	/// @brief In-order traversal (sorted).
	std::vector<T> InOrder() const { return {}; }

	/// @brief Validate red-black properties:
	/// 1. Root is black.
	/// 2. Red nodes have only black children.
	/// 3. All paths from root to leaves have same black-height.
	/// 4. BST ordering.
	bool Validate() const { return true; }

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
