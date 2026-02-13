#pragma once

#include <cstddef>
#include <vector>

namespace datastructures::nodes
{
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

template <typename T>
struct AVLTreeNode
{
	/// @brief Cheia stocată în nod (BST invariant: left < key < right).
	T key;
	/// @brief Numărul de apariții ale cheii (pentru duplicate). Minim 1 pentru nod valid.
	std::size_t count = 1;
	/// @brief Înălțimea nodului (recomandare: frunză => 1). Menținută după insert/erase/rotiri.
	int height = 1;
	/// @brief Subarborele stâng (chei strict mai mici).
	AVLTreeNode* left = nullptr;
	/// @brief Subarborele drept (chei strict mai mari).
	AVLTreeNode* right = nullptr;
};

template <typename T>
using GenericTreeNode = GraphNode<T>;
}  // namespace datastructures::nodes