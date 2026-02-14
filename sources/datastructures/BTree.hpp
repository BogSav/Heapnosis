#pragma once

#include <cstddef>
#include <vector>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief B-Tree of a given order.
/// @tparam T Key type (must be comparable).
/// @tparam Order Maximum number of children per node (minimum degree t = Order/2).
template <typename T, std::size_t Order = 4>
class BTree
{
public:
	using value_type = T;
	using Node = nodes::BTreeNode<T, Order>;

	BTree() = default;
	~BTree() = default;

	BTree(const BTree&) = delete;
	BTree& operator=(const BTree&) = delete;
	BTree(BTree&&) noexcept = default;
	BTree& operator=(BTree&&) noexcept = default;

	/// @brief Insert a key.
	void Insert(const T& /*value*/)
	{
		// TODO: implement — split nodes as needed
	}

	/// @brief Erase a key.
	/// @return true if found and removed.
	bool Erase(const T& /*value*/) { return false; }

	/// @brief Check key existence.
	bool Contains(const T& /*value*/) const { return false; }

	/// @brief Number of keys stored.
	std::size_t Size() const { return 0; }

	/// @brief Whether the tree is empty.
	bool Empty() const { return true; }

	/// @brief In-order traversal.
	std::vector<T> InOrder() const { return {}; }

	/// @brief Validate B-Tree invariants.
	bool Validate() const { return true; }

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
