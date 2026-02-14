#pragma once

#include <cstddef>
#include <string>

#include "Nodes.hpp"

namespace datastructures
{

/// @brief Trie (prefix tree) for lowercase English strings (26-ary).
class Trie
{
public:
	using Node = nodes::TrieNode;

	Trie() = default;
	~Trie() = default;

	Trie(const Trie&) = delete;
	Trie& operator=(const Trie&) = delete;
	Trie(Trie&&) noexcept = default;
	Trie& operator=(Trie&&) noexcept = default;

	/// @brief Insert a word into the trie.
	void Insert(const std::string& /*word*/)
	{
		// TODO: implement
	}

	/// @brief Check if the exact word exists in the trie.
	bool Search(const std::string& /*word*/) const { return false; }

	/// @brief Check if any word in the trie starts with the given prefix.
	bool StartsWith(const std::string& /*prefix*/) const { return false; }

	/// @brief Erase a word from the trie.
	/// @return true if the word existed and was removed.
	bool Erase(const std::string& /*word*/) { return false; }

	/// @brief Number of words stored.
	std::size_t Size() const { return 0; }

	/// @brief Whether the trie is empty.
	bool Empty() const { return true; }

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
