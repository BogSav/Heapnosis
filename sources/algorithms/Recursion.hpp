#pragma once

#include <string>
#include <vector>

namespace algorithms
{

/// @brief Compute n! recursively.
/// @param n Non-negative integer.
/// @return n factorial.
inline long long Factorial(int /*n*/)
{
	// TODO: implement recursive factorial
	return 0;
}

/// @brief Reverse a string recursively.
/// @param s Input string.
/// @return Reversed copy.
inline std::string ReverseString(const std::string& /*s*/)
{
	// TODO: implement recursive string reversal
	return {};
}

/// @brief Solve the N-Queens problem.
/// @param n Board size (n×n).
/// @return All valid queen placements; each solution is a vector of column
///         indices where solution[row] = col.
inline std::vector<std::vector<int>> SolveNQueens(int /*n*/)
{
	// TODO: implement backtracking N-Queens solver
	return {};
}

}  // namespace algorithms
