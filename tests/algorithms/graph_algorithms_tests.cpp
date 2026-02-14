#include <gtest/gtest.h>

#include "Graph.hpp"
#include "GraphAlgorithms.hpp"

namespace
{

using datastructures::AdjacencyListGraph;

TEST(GraphAlgorithmTests, DISABLED_BFSFromSource)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 2);
	g.AddEdge(2, 3);

	auto order = algorithms::BFS(g, 1);
	ASSERT_EQ(order.size(), 3u);
	EXPECT_EQ(order[0], 1);
}

TEST(GraphAlgorithmTests, DISABLED_DFSFromSource)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 2);
	g.AddEdge(2, 3);

	auto order = algorithms::DFS(g, 1);
	ASSERT_EQ(order.size(), 3u);
	EXPECT_EQ(order[0], 1);
}

TEST(GraphAlgorithmTests, DISABLED_ConnectedComponents)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddVertex(4);
	g.AddEdge(1, 2);
	// 3 and 4 are isolated from 1-2

	auto comps = algorithms::ConnectedComponents(g);
	EXPECT_GE(comps.size(), 2u);
}

TEST(GraphAlgorithmTests, DISABLED_DijkstraShortestPaths)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 2, 1);
	g.AddEdge(2, 3, 2);
	g.AddEdge(1, 3, 10);

	auto dist = algorithms::Dijkstra(g, 1);
	EXPECT_EQ(dist[1], 0);
	EXPECT_EQ(dist[2], 1);
	EXPECT_EQ(dist[3], 3);
}

TEST(GraphAlgorithmTests, DISABLED_TopologicalSortIndegree)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddDirectedEdge(1, 2);
	g.AddDirectedEdge(2, 3);

	auto order = algorithms::TopologicalSortIndegree(g);
	ASSERT_EQ(order.size(), 3u);
	EXPECT_EQ(order[0], 1);
	EXPECT_EQ(order[1], 2);
	EXPECT_EQ(order[2], 3);
}

TEST(GraphAlgorithmTests, DISABLED_TopologicalSortDFS)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddDirectedEdge(1, 2);
	g.AddDirectedEdge(2, 3);

	auto order = algorithms::TopologicalSortDFS(g);
	ASSERT_EQ(order.size(), 3u);
}

TEST(GraphAlgorithmTests, DISABLED_FloydWarshall)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(0);
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddDirectedEdge(0, 1, 3);
	g.AddDirectedEdge(1, 2, 1);
	g.AddDirectedEdge(0, 2, 10);

	std::vector<int> vertices = {0, 1, 2};
	auto dist = algorithms::FloydWarshall(g, vertices);
	ASSERT_EQ(dist.size(), 3u);
	EXPECT_EQ(dist[0][2], 4); // 0->1->2 = 3+1
}

TEST(GraphAlgorithmTests, DISABLED_PrimMST)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 2, 1);
	g.AddEdge(2, 3, 2);
	g.AddEdge(1, 3, 3);

	auto mst = algorithms::PrimMST(g);
	EXPECT_EQ(mst.size(), 2u); // n-1 edges for MST
}

TEST(GraphAlgorithmTests, DISABLED_KruskalMST)
{
	AdjacencyListGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 2, 1);
	g.AddEdge(2, 3, 2);
	g.AddEdge(1, 3, 3);

	auto mst = algorithms::KruskalMST(g);
	EXPECT_EQ(mst.size(), 2u);
}

}  // namespace
