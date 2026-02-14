#pragma once

#include <string>
#include <vector>

namespace algorithms
{

/// @brief Compute the nth Fibonacci number using dynamic programming.
/// @param n Non-negative index (F(0)=0, F(1)=1).
/// @return F(n).
inline long long FibonacciDP(int /*n*/)
{
	// TODO: implement bottom-up DP
	return 0;
}

/// @brief Minimum number of coins to make 'amount' from the given denominations.
/// @param amount Target amount.
/// @param coins Available coin denominations.
/// @return Minimum coin count, or -1 if impossible.
inline int MakeChange(int /*amount*/, const std::vector<int>& /*coins*/)
{
	// TODO: implement coin-change DP
	return -1;
}

/// @brief Longest Common Subsequence of two strings.
/// @return The LCS string (not just its length).
inline std::string LongestCommonSubsequence(const std::string& /*a*/, const std::string& /*b*/)
{
	// TODO: implement LCS DP
	return {};
}

}  // namespace algorithms
