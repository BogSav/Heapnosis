#pragma once

#include <cstddef>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace datastructures
{

/// @brief Weighted edge representation.
template <typename T, typename W = int>
struct WeightedEdge
{
	T from;
	T to;
	W weight;
};

/// @brief Adjacency-list graph supporting directed and undirected edges, with optional weights.
/// @tparam T Vertex type (must be hashable).
/// @tparam W Weight type (default int).
template <typename T, typename W = int>
class AdjacencyListGraph
{
public:
	using Edge = WeightedEdge<T, W>;

	AdjacencyListGraph() = default;
	~AdjacencyListGraph() = default;

	/// @brief Add a vertex to the graph.
	/// @return true if the vertex was added (new), false if it already existed.
	bool AddVertex(const T& /*vertex*/)
	{
		// TODO: implement
		return false;
	}

	/// @brief Add an undirected edge between u and v with the given weight.
	void AddEdge(const T& /*u*/, const T& /*v*/, W /*weight*/ = W{})
	{
		// TODO: implement
	}

	/// @brief Add a directed edge from u to v with the given weight.
	void AddDirectedEdge(const T& /*from*/, const T& /*to*/, W /*weight*/ = W{})
	{
		// TODO: implement
	}

	/// @brief Check whether a vertex exists.
	bool HasVertex(const T& /*vertex*/) const { return false; }

	/// @brief Check whether an edge from u to v exists.
	bool HasEdge(const T& /*u*/, const T& /*v*/) const { return false; }

	/// @brief Return the neighbors (and edge weights) of a vertex.
	std::vector<std::pair<T, W>> GetNeighbors(const T& /*vertex*/) const { return {}; }

	/// @brief Return all vertices.
	std::vector<T> GetVertices() const { return {}; }

	/// @brief Number of vertices.
	std::size_t VertexCount() const { return 0; }

	/// @brief Number of edges (directed count; undirected edges count as 2).
	std::size_t EdgeCount() const { return 0; }

	/// @brief Return all edges in the graph.
	std::vector<Edge> GetEdges() const { return {}; }

private:
	// adjacency list: vertex -> list of (neighbor, weight)
	std::unordered_map<T, std::vector<std::pair<T, W>>> _adj;
};

}  // namespace datastructures
