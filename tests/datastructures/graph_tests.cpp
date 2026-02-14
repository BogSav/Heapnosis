#include <gtest/gtest.h>

#include "Graph.hpp"

namespace
{

using datastructures::AdjacencyListGraph;

TEST(GraphTests, NewGraphIsEmpty)
{
	AdjacencyListGraph<int> graph;
	EXPECT_EQ(graph.VertexCount(), 0u);
	EXPECT_EQ(graph.EdgeCount(), 0u);
}

TEST(GraphTests, DISABLED_AddVertexAndEdge)
{
	AdjacencyListGraph<int> graph;
	graph.AddVertex(1);
	graph.AddVertex(2);
	graph.AddEdge(1, 2, 5);
	EXPECT_TRUE(graph.HasVertex(1));
	EXPECT_TRUE(graph.HasVertex(2));
	EXPECT_TRUE(graph.HasEdge(1, 2));
	EXPECT_TRUE(graph.HasEdge(2, 1)); // undirected
	EXPECT_EQ(graph.VertexCount(), 2u);
}

TEST(GraphTests, DISABLED_DirectedEdge)
{
	AdjacencyListGraph<int> graph;
	graph.AddVertex(1);
	graph.AddVertex(2);
	graph.AddDirectedEdge(1, 2, 10);
	EXPECT_TRUE(graph.HasEdge(1, 2));
	EXPECT_FALSE(graph.HasEdge(2, 1));
}

}  // namespace
