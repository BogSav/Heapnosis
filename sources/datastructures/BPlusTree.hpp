#pragma once

#include <cstddef>
#include <vector>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief B+ Tree — B-Tree variant where all values are in leaves and leaves are linked.
/// @tparam T Key type.
/// @tparam Order Maximum number of children per internal node.
template <typename T, std::size_t Order = 4>
class BPlusTree
{
public:
	using value_type = T;
	using Node = nodes::BPlusTreeNode<T, Order>;

	BPlusTree() = default;
	~BPlusTree() = default;

	BPlusTree(const BPlusTree&) = delete;
	BPlusTree& operator=(const BPlusTree&) = delete;
	BPlusTree(BPlusTree&&) noexcept = default;
	BPlusTree& operator=(BPlusTree&&) noexcept = default;

	/// @brief Insert a key.
	void Insert(const T& /*value*/)
	{
		// TODO: implement
	}

	/// @brief Erase a key.
	/// @return true if found and removed.
	bool Erase(const T& /*value*/) { return false; }

	/// @brief Check key existence.
	bool Contains(const T& /*value*/) const { return false; }

	/// @brief Range query: return all keys in [low, high].
	std::vector<T> RangeQuery(const T& /*low*/, const T& /*high*/) const { return {}; }

	/// @brief Number of keys stored.
	std::size_t Size() const { return 0; }

	/// @brief Whether the tree is empty.
	bool Empty() const { return true; }

	/// @brief In-order traversal (via leaf chain).
	std::vector<T> InOrder() const { return {}; }

	/// @brief Validate B+ Tree invariants.
	bool Validate() const { return true; }

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
