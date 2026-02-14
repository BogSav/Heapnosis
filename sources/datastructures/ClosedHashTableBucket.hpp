#pragma once

#include <cstddef>
#include <functional>
#include <optional>
#include <utility>
#include <vector>

namespace datastructures
{

/// @brief Closed Hash Table with bucket overflow areas.
/// Uses open addressing with a separate overflow region when primary slots collide.
template <typename K, typename V, typename Hash = std::hash<K>>
class ClosedHashTableBucket
{
public:
	using value_type = std::pair<K, V>;

	explicit ClosedHashTableBucket(std::size_t primaryCapacity = 16, std::size_t overflowCapacity = 8)
		: _primary(primaryCapacity),
		  _primaryUsed(primaryCapacity, false),
		  _overflow(overflowCapacity),
		  _overflowUsed(overflowCapacity, false)
	{
	}

	~ClosedHashTableBucket() = default;

	/// @brief Insert or update a key-value pair.
	void Insert(const K& /*key*/, const V& /*value*/)
	{
		// TODO: implement — try primary slot, overflow on collision
	}

	/// @brief Erase a key.
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
	std::vector<value_type> _primary;
	std::vector<bool> _primaryUsed;
	std::vector<value_type> _overflow;
	std::vector<bool> _overflowUsed;
	std::size_t _size = 0;
	Hash _hash;
};

}  // namespace datastructures
