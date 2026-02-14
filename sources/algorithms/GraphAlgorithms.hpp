#pragma once

#include <limits>
#include <queue>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Graph.hpp"

namespace algorithms
{

/// @brief Breadth-First Search starting from a source vertex.
/// @return Vertices in BFS visit order.
template <typename T, typename W>
std::vector<T> BFS(const datastructures::AdjacencyListGraph<T, W>& /*graph*/, const T& /*source*/)
{
	// TODO: implement
	return {};
}

/// @brief Depth-First Search starting from a source vertex.
/// @return Vertices in DFS visit order.
template <typename T, typename W>
std::vector<T> DFS(const datastructures::AdjacencyListGraph<T, W>& /*graph*/, const T& /*source*/)
{
	// TODO: implement
	return {};
}

/// @brief Find all connected components in an undirected graph.
/// @return A vector of components, each component is a set of vertices.
template <typename T, typename W>
std::vector<std::vector<T>> ConnectedComponents(const datastructures::AdjacencyListGraph<T, W>& /*graph*/)
{
	// TODO: implement
	return {};
}

/// @brief Dijkstra's shortest-path from source.
/// @return Map from vertex to shortest distance.
template <typename T, typename W>
std::unordered_map<T, W> Dijkstra(const datastructures::AdjacencyListGraph<T, W>& /*graph*/, const T& /*source*/)
{
	// TODO: implement
	return {};
}

/// @brief Prim's Minimum Spanning Tree.
/// @return Edges in the MST.
template <typename T, typename W>
std::vector<datastructures::WeightedEdge<T, W>> PrimMST(const datastructures::AdjacencyListGraph<T, W>& /*graph*/)
{
	// TODO: implement
	return {};
}

/// @brief Topological sort using indegree (Kahn's algorithm).
/// @return Vertices in topological order, or empty if cycle detected.
template <typename T, typename W>
std::vector<T> TopologicalSortIndegree(const datastructures::AdjacencyListGraph<T, W>& /*graph*/)
{
	// TODO: implement
	return {};
}

/// @brief Topological sort using DFS.
/// @return Vertices in topological order, or empty if cycle detected.
template <typename T, typename W>
std::vector<T> TopologicalSortDFS(const datastructures::AdjacencyListGraph<T, W>& /*graph*/)
{
	// TODO: implement
	return {};
}

/// @brief Floyd–Warshall all-pairs shortest paths.
/// @param vertices Ordered list of vertices.
/// @return 2D distance matrix (same index order as vertices).
template <typename T, typename W>
std::vector<std::vector<W>> FloydWarshall(
	const datastructures::AdjacencyListGraph<T, W>& /*graph*/,
	const std::vector<T>& /*vertices*/)
{
	// TODO: implement
	return {};
}

/// @brief Kruskal's Minimum Spanning Tree using Union-Find.
/// @return Edges in the MST.
template <typename T, typename W>
std::vector<datastructures::WeightedEdge<T, W>> KruskalMST(const datastructures::AdjacencyListGraph<T, W>& /*graph*/)
{
	// TODO: implement
	return {};
}

}  // namespace algorithms
