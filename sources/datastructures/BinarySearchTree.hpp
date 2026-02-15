#pragma once

#include "Nodes.hpp"

#include <cstddef>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

namespace datastructures
{

/// @brief Unbalanced Binary Search Tree.
template <typename T>
class BinarySearchTree
{
public:
	using value_type = T;
	using Node = nodes::BinaryTreeNode<T>;

	BinarySearchTree() = default;
	~BinarySearchTree() = default;

	BinarySearchTree(const BinarySearchTree&) = delete;
	BinarySearchTree& operator=(const BinarySearchTree&) = delete;
	BinarySearchTree(BinarySearchTree&&) noexcept = default;
	BinarySearchTree& operator=(BinarySearchTree&&) noexcept = default;

	/// @brief Insert a key into the BST.
	/// @return true if new node created, false if duplicate.
	bool Insert(const T& value)
	{
		if (Contains(value))
			return false;

		if (!_root)
		{
			_root = new Node(value, nullptr, nullptr);
			_size = 1;
			return true;
		}

		Node* current = _root;
		while (true)
		{
			if (value < current->data)
			{
				if (current->left == nullptr)
				{
					current->left = new Node(value, nullptr, nullptr);
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if (current->right == nullptr)
				{
					current->right = new Node(value, nullptr, nullptr);
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}

		_size++;

		return true;
	}

	/// @brief Erase a key from the BST.
	/// @return true if the key existed and was removed.
	bool Erase(const T& value)
	{
		Node* current = _root;
		Node* parent = nullptr;

		while (current != nullptr && current->data != value)
		{
			parent = current;
			if (value < current->data)
				current = current->left;
			else
				current = current->right;
		}

		if (current == nullptr)
			return false;

		if (current->left == nullptr || current->right == nullptr)
		{
			Node* temp = (current->left != nullptr) ? current->left : current->right;

			if (parent == nullptr)
			{
				_root = temp;
			}
			else
			{
				if (parent->left == current)
					parent->left = temp;
				else
					parent->right = temp;
			}
			delete current;
		}
		else
		{
			Node* predecessorParent = current;
			Node* predecessor = current->left;

			while (predecessor->right != nullptr)
			{
				predecessorParent = predecessor;
				predecessor = predecessor->right;
			}

			current->data = predecessor->data;

			if (predecessorParent == current)
			{
				predecessorParent->left = predecessor->left;
			}
			else
			{
				predecessorParent->right = predecessor->left;
			}
			delete predecessor;
		}

		_size--;
		return true;
	}

	/// @brief Check whether the key exists.
	bool Contains(const T& value) const
	{
		Node* current = _root;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				return true;
			}
			current = value < current->data ? current->left : current->right;
		}

		return false;
	}

	/// @brief Number of elements.
	std::size_t Size() const { return _size; }

	/// @brief Whether the tree is empty.
	bool Empty() const { return _size == 0 && _root == nullptr; }

	/// @brief Height of the tree (0 for empty).
	int Height() const
	{
		if (_root == nullptr)
			return 0;

		std::stack<std::pair<Node*, int>> q;
		q.push({_root, 1});

		int maxHeight = 0;

		while (!q.empty())
		{
			auto [current, currentHeight] = q.top();
			q.pop();

			if (current->right != nullptr)
			{
				q.push({current->right, currentHeight + 1});
			}

			if (current->left != nullptr)
			{
				q.push({current->left, currentHeight + 1});
			}

			if (current->left == nullptr && current->right == nullptr)
			{
				if (currentHeight > maxHeight)
					maxHeight = currentHeight;
			}
		}

		return maxHeight;
	}

	/// This is the Height implememtation using a queue
	int HeightWithQueue()
	{
		if (_root == nullptr)
			return 0;

		std::queue<Node*> q;
		q.push(_root);
		int levels = 0;

		while (!q.empty())
		{
			int nodesAtCurrentLevel = q.size();
			levels++;

			for (int i = 0; i < nodesAtCurrentLevel; i++)
			{
				Node* current = q.front();
				q.pop();

				if (current->left)
					q.push(current->left);
				if (current->right)
					q.push(current->right);
			}
		}
		return levels;
	}

	/// @brief In-order traversal (sorted).
	std::vector<T> InOrder() const
	{
		if (_root == nullptr)
			return {};

		std::vector<T> v;
		std::stack<Node*> s;
		Node* current = _root;

		while (current != nullptr || !s.empty())
		{
			while (current != nullptr)
			{
				s.push(current);
				current = current->left;
			}

			current = s.top();
			s.pop();

			v.push_back(current->data);

			current = current->right;
		}

		return v;
	}

	/// @brief Validate BST property.
	bool Validate() const
	{
		if (_root == nullptr)
			return true;

		std::stack<Node*> s;
		Node* current = _root;
		Node* prev = nullptr;

		while (current != nullptr || !s.empty())
		{
			while (current != nullptr)
			{
				s.push(current);
				current = current->left;
			}
			current = s.top();
			s.pop();

			if (prev != nullptr && current->data <= prev->data)
				return false;

			prev = current;
			current = current->right;
		}
		return true;
	}

private:
	Node* _root = nullptr;
	std::size_t _size = 0;
};

}  // namespace datastructures
