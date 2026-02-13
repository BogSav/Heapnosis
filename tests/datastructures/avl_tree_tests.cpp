#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <random>
#include <set>
#include <type_traits>
#include <vector>

#include "AVLTree.hpp"

namespace
{
// Contractul de API pe care aceste teste îl așteaptă de la AVLTree.
// Ideea: tu implementezi AVLTree.cpp / AVLTree.hpp astfel încât să satisfacă acest contract.
// - Duplicate permise: Count(x) crește, Size() numără toate aparițiile.
// - InOrder() întoarce elementele sortate, inclusiv duplicatele (repetate).
// - Validate() verifică invarianta BST + invarianta AVL (balance factor in [-1, 1]) + height-uri corecte.

template <typename Tree>
concept AvlTreeContract = requires(Tree tree, const Tree ctree, typename Tree::value_type v) {
	{ Tree{} };
	{ tree.Insert(v) } -> std::same_as<bool>;
	{ tree.Erase(v) } -> std::same_as<bool>;
	{ ctree.Contains(v) } -> std::same_as<bool>;
	{ ctree.Count(v) } -> std::same_as<std::size_t>;
	{ ctree.Size() } -> std::same_as<std::size_t>;
	{ ctree.Empty() } -> std::same_as<bool>;
	{ ctree.Height() } -> std::same_as<int>;
	{ ctree.InOrder() } -> std::same_as<std::vector<typename Tree::value_type>>;
	{ ctree.Validate() } -> std::same_as<bool>;
};

using datastructures::AVLTree;
using IntAVL = AVLTree<int>;

static_assert(AvlTreeContract<IntAVL>,
	"AVLTree<int> must provide: value_type, Insert, Erase, Contains, Count, Size, Empty, Height, InOrder, Validate");

static std::vector<int> ToVector(const std::multiset<int>& set)
{
	return std::vector<int>(set.begin(), set.end());
}

TEST(AVLTreeTests, NewTreeIsEmpty)
{
	IntAVL tree;
	EXPECT_TRUE(tree.Empty());
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_EQ(tree.Height(), 0);
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());

	EXPECT_FALSE(tree.Contains(123));
	EXPECT_EQ(tree.Count(123), 0u);
}

TEST(AVLTreeTests, InsertSingleElement)
{
	IntAVL tree;
	EXPECT_TRUE(tree.Insert(10));
	EXPECT_FALSE(tree.Empty());
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(10));
	EXPECT_EQ(tree.Count(10), 1u);
	EXPECT_EQ(tree.InOrder(), (std::vector<int>{10}));
	EXPECT_TRUE(tree.Validate());
}

TEST(AVLTreeTests, InsertDuplicatesIncrementsCount)
{
	IntAVL tree;
	EXPECT_TRUE(tree.Insert(7));
	EXPECT_FALSE(tree.Insert(7));
	EXPECT_FALSE(tree.Insert(7));

	EXPECT_TRUE(tree.Contains(7));
	EXPECT_EQ(tree.Count(7), 3u);
	EXPECT_EQ(tree.Size(), 3u);
	EXPECT_EQ(tree.InOrder(), (std::vector<int>{7, 7, 7}));
	EXPECT_TRUE(tree.Validate());
}

TEST(AVLTreeTests, EraseDecrementsCountAndRemovesNodeAtZero)
{
	IntAVL tree;
	EXPECT_TRUE(tree.Insert(5));
	EXPECT_FALSE(tree.Insert(5));
	EXPECT_FALSE(tree.Insert(5));
	EXPECT_EQ(tree.Count(5), 3u);
	EXPECT_EQ(tree.Size(), 3u);

	EXPECT_TRUE(tree.Erase(5));
	EXPECT_EQ(tree.Count(5), 2u);
	EXPECT_EQ(tree.Size(), 2u);
	EXPECT_TRUE(tree.Contains(5));
	EXPECT_TRUE(tree.Validate());

	EXPECT_TRUE(tree.Erase(5));
	EXPECT_EQ(tree.Count(5), 1u);
	EXPECT_EQ(tree.Size(), 1u);
	EXPECT_TRUE(tree.Contains(5));
	EXPECT_TRUE(tree.Validate());

	EXPECT_TRUE(tree.Erase(5));
	EXPECT_EQ(tree.Count(5), 0u);
	EXPECT_EQ(tree.Size(), 0u);
	EXPECT_FALSE(tree.Contains(5));
	EXPECT_TRUE(tree.InOrder().empty());
	EXPECT_TRUE(tree.Validate());

	EXPECT_FALSE(tree.Erase(5));
	EXPECT_TRUE(tree.Validate());
}

TEST(AVLTreeTests, InOrderIsSortedAndIncludesDuplicates)
{
	IntAVL tree;
	std::multiset<int> ref;

	const std::vector<int> values = {10, 4, 20, 15, 15, 7, 4, 4, 9, 30, 2};
	for (int x : values)
	{
		ref.insert(x);
		tree.Insert(x);
		ASSERT_TRUE(tree.Validate());
	}

	EXPECT_EQ(tree.Size(), ref.size());
	EXPECT_EQ(tree.InOrder(), ToVector(ref));
}

TEST(AVLTreeTests, ClassicRotationScenariosStayBalanced)
{
	{
		IntAVL tree;
		tree.Insert(3);
		tree.Insert(2);
		tree.Insert(1);
		EXPECT_TRUE(tree.Validate());
		EXPECT_EQ(tree.InOrder(), (std::vector<int>{1, 2, 3}));
		EXPECT_LE(tree.Height(), 2);
	}
	{
		IntAVL tree;
		tree.Insert(1);
		tree.Insert(2);
		tree.Insert(3);
		EXPECT_TRUE(tree.Validate());
		EXPECT_EQ(tree.InOrder(), (std::vector<int>{1, 2, 3}));
		EXPECT_LE(tree.Height(), 2);
	}
	{
		IntAVL tree;
		tree.Insert(3);
		tree.Insert(1);
		tree.Insert(2);
		EXPECT_TRUE(tree.Validate());
		EXPECT_EQ(tree.InOrder(), (std::vector<int>{1, 2, 3}));
		EXPECT_LE(tree.Height(), 2);
	}
	{
		IntAVL tree;
		tree.Insert(1);
		tree.Insert(3);
		tree.Insert(2);
		EXPECT_TRUE(tree.Validate());
		EXPECT_EQ(tree.InOrder(), (std::vector<int>{1, 2, 3}));
		EXPECT_LE(tree.Height(), 2);
	}
}

TEST(AVLTreeTests, HeightIsLogarithmicForSequentialInserts)
{
	IntAVL tree;
	const int n = 1000;
	for (int i = 1; i <= n; ++i)
	{
		tree.Insert(i);
		ASSERT_TRUE(tree.Validate());
	}

	// Bound lejer (în practică AVL e mult mai bun). Dacă Height() e 0 pentru gol,
	// o înălțime log(n) ar trebui să fie mult sub acest prag.
	const double log2n = std::log2(static_cast<double>(n) + 1.0);
	const int maxAllowed = static_cast<int>(std::ceil(2.0 * log2n + 2.0));
	EXPECT_LE(tree.Height(), maxAllowed);
}

TEST(AVLTreeTests, RandomizedFuzzMatchesMultisetAndAlwaysValid)
{
	IntAVL tree;
	std::multiset<int> ref;

	std::mt19937 rng(1337);
	std::uniform_int_distribution<int> valueDist(-50, 50);
	std::uniform_int_distribution<int> opDist(0, 2); // 0=insert, 1=erase, 2=contains

	for (int step = 0; step < 800; ++step)
	{
		const int v = valueDist(rng);
		switch (opDist(rng))
		{
			case 0:
			{
				const bool insertedNew = tree.Insert(v);
				const bool wasNew = (ref.count(v) == 0);
				ref.insert(v);
				EXPECT_EQ(insertedNew, wasNew);
				break;
			}
			case 1:
			{
				const bool erased = tree.Erase(v);
				auto it = ref.find(v);
				const bool refErased = (it != ref.end());
				if (refErased)
					ref.erase(it);
				EXPECT_EQ(erased, refErased);
				break;
			}
			case 2:
			{
				EXPECT_EQ(tree.Contains(v), ref.find(v) != ref.end());
				break;
			}
			default:
				break;
		}

		ASSERT_TRUE(tree.Validate());
		EXPECT_EQ(tree.Size(), ref.size());
		EXPECT_EQ(tree.InOrder(), ToVector(ref));

		// sanity: Count() corect pe câteva chei
		for (int probe : { -50, -1, 0, 1, 7, 50 })
		{
			EXPECT_EQ(tree.Count(probe), ref.count(probe));
		}
	}
}
}  // namespace
