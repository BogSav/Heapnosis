#pragma once

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
using GenericTreeNode = GraphNode<T>;
}  // namespace datastructures::nodes