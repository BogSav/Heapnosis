#pragma once

#include <cstddef>
#include <unordered_map>

namespace datastructures
{

/// @brief Disjoint Sets (Union-Find) with union by rank and path compression.
/// @tparam T Element type (must be hashable).
template <typename T>
class DisjointSets
{
public:
	DisjointSets() = default;
	~DisjointSets() = default;

	/// @brief Create a new singleton set containing x.
	void MakeSet(const T& /*x*/)
	{
		// TODO: implement
	}

	/// @brief Find the representative of the set containing x (with path compression).
	T Find(const T& /*x*/)
	{
		// TODO: implement
		return T{};
	}

	/// @brief Union the sets containing x and y (by rank).
	void Union(const T& /*x*/, const T& /*y*/)
	{
		// TODO: implement
	}

	/// @brief Check if x and y are in the same set.
	bool Connected(const T& /*x*/, const T& /*y*/)
	{
		// TODO: implement
		return false;
	}

	/// @brief Number of total elements across all sets.
	std::size_t Size() const { return _parent.size(); }

	/// @brief Number of disjoint sets.
	std::size_t SetCount() const { return 0; }

private:
	std::unordered_map<T, T> _parent;
	std::unordered_map<T, int> _rank;
};

}  // namespace datastructures
