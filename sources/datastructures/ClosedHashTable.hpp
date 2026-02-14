#pragma once

#include <cstddef>
#include <functional>
#include <optional>
#include <utility>
#include <vector>

namespace datastructures
{

/// @brief Closed Hash Table (open addressing / linear probing).
template <typename K, typename V, typename Hash = std::hash<K>>
class ClosedHashTable
{
public:
	using value_type = std::pair<K, V>;

	explicit ClosedHashTable(std::size_t capacity = 16)
		: _slots(capacity), _occupied(capacity, false), _deleted(capacity, false)
	{
	}

	~ClosedHashTable() = default;

	/// @brief Insert or update a key-value pair.
	void Insert(const K& /*key*/, const V& /*value*/)
	{
		// TODO: implement — hash, probe, place
	}

	/// @brief Erase a key (lazy deletion).
	/// @return true if found and removed.
	bool Erase(const K& /*key*/) { return false; }

	/// @brief Find a value by key.
	std::optional<V> Find(const K& /*key*/) const { return std::nullopt; }

	/// @brief Check if a key exists.
	bool Contains(const K& /*key*/) const { return false; }

	/// @brief Number of stored pairs.
	std::size_t Size() const { return 0; }

	/// @brief Whether the table is empty.
	bool Empty() const { return true; }

private:
	std::vector<value_type> _slots;
	std::vector<bool> _occupied;
	std::vector<bool> _deleted;
	std::size_t _size = 0;
	Hash _hash;
};

}  // namespace datastructures
