#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace datastructures::nodes
{
// ── Linked-list nodes ──────────────────────────────────────────────────

template <typename T>
struct ForwardListNode
{
	T data;
	ForwardListNode* next = nullptr;
};

template <typename T>
struct DoublyLinkedListNode
{
	T data;
	DoublyLinkedListNode* next = nullptr;
	DoublyLinkedListNode* prev = nullptr;
};

// ── Generic tree / graph nodes ─────────────────────────────────────────

template <typename T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode* left = nullptr;
	BinaryTreeNode* right = nullptr;
};

template <typename T>
struct GraphNode
{
	T data;
	std::vector<GraphNode*> neighbors;
};

// ── BST / balanced-tree nodes ──────────────────────────────────────────

template <typename T>
struct AVLTreeNode
{
	T key;
	std::size_t count = 1;
	int height = 1;
	AVLTreeNode* left = nullptr;
	AVLTreeNode* right = nullptr;
};

/// @brief Nodul pentru Red-Black Tree.
enum class RBColor
{
	Red,
	Black
};

template <typename T>
struct RedBlackTreeNode
{
	T key;
	RBColor color = RBColor::Red;
	RedBlackTreeNode* left = nullptr;
	RedBlackTreeNode* right = nullptr;
	RedBlackTreeNode* parent = nullptr;
};

/// @brief Nodul pentru Splay Tree (identic structural cu BinaryTreeNode cu parent).
template <typename T>
struct SplayTreeNode
{
	T key;
	SplayTreeNode* left = nullptr;
	SplayTreeNode* right = nullptr;
	SplayTreeNode* parent = nullptr;
};

// ── B-Tree / B+ Tree nodes ────────────────────────────────────────────

template <typename T, std::size_t Order>
struct BTreeNode
{
	bool leaf = true;
	std::vector<T> keys;
	std::vector<BTreeNode*> children;
};

template <typename T, std::size_t Order>
struct BPlusTreeNode
{
	bool leaf = true;
	std::vector<T> keys;
	std::vector<BPlusTreeNode*> children;
	BPlusTreeNode* next = nullptr;  // linked-list pointer for leaf level
};

// ── Trie / Radix / Ternary Search Tree nodes ──────────────────────────

struct TrieNode
{
	static constexpr int ALPHABET_SIZE = 26;
	std::array<TrieNode*, ALPHABET_SIZE> children{};
	bool isEndOfWord = false;
};

struct RadixTreeNode
{
	std::string edgeLabel;
	std::vector<RadixTreeNode*> children;
	bool isEndOfWord = false;
};

template <typename T>
struct TernarySearchTreeNode
{
	T data;
	bool isEndOfWord = false;
	TernarySearchTreeNode* left = nullptr;
	TernarySearchTreeNode* equal = nullptr;
	TernarySearchTreeNode* right = nullptr;
};

// ── Heap nodes ─────────────────────────────────────────────────────────

template <typename T>
struct BinomialNode
{
	T key;
	int degree = 0;
	BinomialNode* parent = nullptr;
	BinomialNode* child = nullptr;
	BinomialNode* sibling = nullptr;
};

template <typename T>
struct FibonacciNode
{
	T key;
	int degree = 0;
	bool marked = false;
	FibonacciNode* parent = nullptr;
	FibonacciNode* child = nullptr;
	FibonacciNode* left = nullptr;
	FibonacciNode* right = nullptr;
};

template <typename T>
struct LeftistNode
{
	T key;
	int rank = 0;  // null-path length
	LeftistNode* left = nullptr;
	LeftistNode* right = nullptr;
};

template <typename T>
struct SkewNode
{
	T key;
	SkewNode* left = nullptr;
	SkewNode* right = nullptr;
};

// ── Disjoint Sets ──────────────────────────────────────────────────────

template <typename T>
struct DisjointSetElement
{
	T data;
	DisjointSetElement* parent = nullptr;
	int rank = 0;
};

// ── Aliases ────────────────────────────────────────────────────────────

template <typename T>
using GenericTreeNode = GraphNode<T>;
}  // namespace datastructures::nodes