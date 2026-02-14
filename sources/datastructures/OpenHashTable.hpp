#pragma once

#include <cstddef>
#include <functional>
#include <list>
#include <optional>
#include <utility>
#include <vector>

namespace datastructures
{

/// @brief Open Hash Table (chaining / closed addressing).
/// Each bucket is a linked list of key-value pairs.
template <typename K, typename V, typename Hash = std::hash<K>>
class OpenHashTable
{
public:
	using value_type = std::pair<K, V>;

	explicit OpenHashTable(std::size_t bucketCount = 16)
		: _buckets(bucketCount)
	{
	}

	~OpenHashTable() = default;

	/// @brief Insert or update a key-value pair.
	void Insert(const K& /*key*/, const V& /*value*/)
	{
		// TODO: implement — hash, find bucket, append/update
	}

	/// @brief Erase a key.
	/// @return true if found and removed.
	bool Erase(const K& /*key*/) { return false; }

	/// @brief Find a value by key.
	/// @return The value if found.
	std::optional<V> Find(const K& /*key*/) const { return std::nullopt; }

	/// @brief Check if a key exists.
	bool Contains(const K& /*key*/) const { return false; }

	/// @brief Number of key-value pairs.
	std::size_t Size() const { return 0; }

	/// @brief Whether the table is empty.
	bool Empty() const { return true; }

private:
	std::vector<std::list<value_type>> _buckets;
	std::size_t _size = 0;
	Hash _hash;
};

}  // namespace datastructures
