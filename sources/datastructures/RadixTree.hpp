#pragma once

#include <cstddef>
#include <string>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Radix Tree (compact / compressed trie) for strings.
class RadixTree
{
public:
	using Node = nodes::RadixTreeNode;

	RadixTree() = default;
	~RadixTree() = default;

	RadixTree(const RadixTree&) = delete;
	RadixTree& operator=(const RadixTree&) = delete;
	RadixTree(RadixTree&&) noexcept = default;
	RadixTree& operator=(RadixTree&&) noexcept = default;

	/// @brief Insert a word.
	void Insert(const std::string& /*word*/)
	{
		// TODO: implement — split edges as needed
	}

	/// @brief Check if the exact word exists.
	bool Search(const std::string& /*word*/) const { return false; }

	/// @brief Check if any word starts with the given prefix.
	bool StartsWith(const std::string& /*prefix*/) const { return false; }

	/// @brief Erase a word.
	/// @return true if the word existed and was removed.
	bool Erase(const std::string& /*word*/) { return false; }

	/// @brief Number of words stored.
	std::size_t Size() const { return 0; }

	/// @brief Whether the tree is empty.
	bool Empty() const { return true; }

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
