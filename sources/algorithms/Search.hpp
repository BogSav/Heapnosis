#pragma once

#include <iterator>

namespace algorithms
{

/// @brief Linear search over a range [first, last).
/// @return Iterator to the found element, or last if not found.
template <typename It, typename T>
It LinearSearch(It first, It last, const T& value)
{
	// TODO: implement linear scan
	(void)value;
	return last;
}

/// @brief Binary search over a *sorted* range [first, last).
/// @return Iterator to the found element, or last if not found.
template <typename It, typename T>
It BinarySearch(It first, It last, const T& value)
{
	// TODO: implement binary search
	(void)value;
	(void)first;
	return last;
}

}  // namespace algorithms
