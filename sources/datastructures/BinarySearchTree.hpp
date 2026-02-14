#pragma once

#include <cstddef>
#include <vector>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Unbalanced Binary Search Tree.
template <typename T>
class BinarySearchTree
{
public:
	using value_type = T;
	using Node = nodes::BinaryTreeNode<T>;

	BinarySearchTree() = default;
	~BinarySearchTree() = default;

	BinarySearchTree(const BinarySearchTree&) = delete;
	BinarySearchTree& operator=(const BinarySearchTree&) = delete;
	BinarySearchTree(BinarySearchTree&&) noexcept = default;
	BinarySearchTree& operator=(BinarySearchTree&&) noexcept = default;

	/// @brief Insert a key into the BST.
	/// @return true if new node created, false if duplicate.
	bool Insert(const T& /*value*/) { return false; }

	/// @brief Erase a key from the BST.
	/// @return true if the key existed and was removed.
	bool Erase(const T& /*value*/) { return false; }

	/// @brief Check whether the key exists.
	bool Contains(const T& /*value*/) const { return false; }

	/// @brief Number of elements.
	std::size_t Size() const { return 0; }

	/// @brief Whether the tree is empty.
	bool Empty() const { return true; }

	/// @brief Height of the tree (0 for empty).
	int Height() const { return 0; }

	/// @brief In-order traversal (sorted).
	std::vector<T> InOrder() const { return {}; }

	/// @brief Validate BST property.
	bool Validate() const { return true; }

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
