#include "BinarySearchTree.hpp"

#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <random>
#include <vector>

namespace
{

using datastructures::BinarySearchTree;
using IntBST = BinarySearchTree<int>;

// Testează inserarea de duplicate (ar trebui să returneze false)
TEST(BinarySearchTreeComplexTests, DuplicateInsertions)
{
	IntBST tree;
	EXPECT_TRUE(tree.Insert(10));
	EXPECT_FALSE(tree.Insert(10));  // Duplicate
	EXPECT_EQ(tree.Size(), 1u);
}

// Testează ștergerea dintr-un arbore gol sau a unei chei inexistente
TEST(BinarySearchTreeComplexTests, EraseNonExistent)
{
	IntBST tree;
	EXPECT_FALSE(tree.Erase(10));
	tree.Insert(5);
	EXPECT_FALSE(tree.Erase(10));
	EXPECT_EQ(tree.Size(), 1u);
}

// Testează ștergerea rădăcinii în toate scenariile
TEST(BinarySearchTreeComplexTests, EraseRootScenarios)
{
	// Rădăcină singură
	{
		IntBST tree;
		tree.Insert(10);
		EXPECT_TRUE(tree.Erase(10));
		EXPECT_TRUE(tree.Empty());
	}
	// Rădăcină cu un singur copil (dreapta)
	{
		IntBST tree;
		tree.Insert(10);
		tree.Insert(15);
		EXPECT_TRUE(tree.Erase(10));
		EXPECT_EQ(tree.InOrder(), (std::vector<int>{15}));
	}
	// Rădăcină cu doi copii
	{
		IntBST tree;
		tree.Insert(10);
		tree.Insert(5);
		tree.Insert(15);
		EXPECT_TRUE(tree.Erase(10));
		EXPECT_TRUE(tree.Validate());
		EXPECT_EQ(tree.Size(), 2u);
		EXPECT_FALSE(tree.Contains(10));
	}
}

// Testează ștergerea unui nod cu 2 copii unde predecesorul este chiar copilul stâng
// (Acesta testează cazul special 'predecessorParent == current' din codul tău)
TEST(BinarySearchTreeComplexTests, EraseNodeWithTwoChildrenComplex)
{
	IntBST tree;
	// Structură: 50 -> (30, 70), 30 -> (20, nullptr)
	// Predecesorul lui 30 este 20.
	tree.Insert(50);
	tree.Insert(30);
	tree.Insert(70);
	tree.Insert(20);
	tree.Insert(40);
	tree.Insert(35);  // Nepot drept pentru 30

	// Ștergem 30 care are doi copii (20 și 40)
	EXPECT_TRUE(tree.Erase(30));
	EXPECT_TRUE(tree.Validate());
	EXPECT_EQ(tree.InOrder(), (std::vector<int>{20, 35, 40, 50, 70}));
}

// Testează un arbore foarte mare și "degradat" (ca o listă)
TEST(BinarySearchTreeComplexTests, SkewedTreePerformanceAndCorrectness)
{
	IntBST tree;
	int n = 1000;
	for (int i = 1; i <= n; ++i)
	{
		tree.Insert(i);
	}
	EXPECT_EQ(tree.Size(), (size_t)n);
	EXPECT_EQ(tree.Height(), n);  // Skewed
	EXPECT_TRUE(tree.Validate());

	// Ștergem elemente din mijloc, capăt și început
	EXPECT_TRUE(tree.Erase(1));  // Început (nouă rădăcină)
	EXPECT_TRUE(tree.Erase(n));  // Final (frunză)
	EXPECT_TRUE(tree.Erase(n / 2));  // Mijloc
	EXPECT_EQ(tree.Size(), (size_t)n - 3);
	EXPECT_TRUE(tree.Validate());
}

// Test de stres: inserări și ștergeri masive
TEST(BinarySearchTreeComplexTests, StressTest)
{
	IntBST tree;
	std::vector<int> data(500);
	std::iota(data.begin(), data.end(), 1);  // 1, 2, ..., 500

	// Shuffle pentru a crea un arbore mai echilibrat
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(data.begin(), data.end(), g);

	for (int x : data)
		tree.Insert(x);
	EXPECT_TRUE(tree.Validate());

	std::shuffle(data.begin(), data.end(), g);
	// Ștergem jumătate din elemente
	for (int i = 0; i < 250; ++i)
	{
		EXPECT_TRUE(tree.Erase(data[i]));
	}

	EXPECT_EQ(tree.Size(), 250u);
	EXPECT_TRUE(tree.Validate());
}

}  // namespace