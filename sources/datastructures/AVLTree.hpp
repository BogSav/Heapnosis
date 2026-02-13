#pragma once

#include <cstddef>
#include <vector>

#include "Nodes.hpp"

namespace datastructures
{
template <typename T>
class AVLTree
{
public:
	using value_type = T;
	using Node = datastructures::nodes::AVLTreeNode<T>;

	AVLTree() = default;
	~AVLTree() = default;

	AVLTree(const AVLTree&) = delete;
	AVLTree& operator=(const AVLTree&) = delete;
	AVLTree(AVLTree&&) noexcept = default;
	AVLTree& operator=(AVLTree&&) noexcept = default;

	/// @brief Inserează o cheie în AVL.
	/// @details
	/// - Menține proprietatea de BST și proprietatea AVL (|balance factor| <= 1).
	/// - Duplicatele sunt permise: dacă cheia există deja, incrementează contorul nodului.
	/// @return true dacă s-a inserat o cheie nouă (nod nou), false dacă a fost duplicat.
	bool Insert(const T& /*value*/) { return false; }

	/// @brief Șterge o apariție a cheii.
	/// @details
	/// - Dacă nodul are count > 1, doar decrementează count.
	/// - Dacă count ajunge la 0, elimină nodul din arbore.
	/// - Reechilibrează arborele (rotiri) după ștergere.
	/// @return true dacă a existat cheia și s-a șters o apariție, altfel false.
	bool Erase(const T& /*value*/) { return false; }

	/// @brief Verifică dacă cheia există în arbore.
	bool Contains(const T& /*value*/) const { return false; }

	/// @brief Numărul de apariții ale cheii (0 dacă nu există).
	std::size_t Count(const T& /*value*/) const { return 0; }

	/// @brief Numărul total de elemente din arbore (inclusiv duplicatele).
	std::size_t Size() const { return 0; }

	/// @brief true dacă arborele nu conține niciun element.
	bool Empty() const { return true; }

	/// @brief Înălțimea arborelui.
	/// @details Recomandare: arbore gol => 0, un singur nod => 1.
	int Height() const { return 0; }

	/// @brief Parcurgere inorder.
	/// @details Returnează elementele sortate crescător; duplicatele apar repetat de `count` ori.
	std::vector<T> InOrder() const { return {}; }

	/// @brief Verifică invarianta BST + AVL.
	/// @details Util în teste: verifică ordinea cheilor, height corecte și balansarea (bf ∈ {-1,0,1}).
	bool Validate() const { return true; }

private:
	Node* _root = nullptr;
};
} // namespace datastructures
