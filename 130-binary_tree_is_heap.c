#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_complete(tree, 0, count_nodes(tree)) ||
	    !is_max_heap(tree))
		return (0);

	return (1);
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: The index of the current node
 * @count: The total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, count) &&
		is_complete(tree->right, 2 * index + 2, count));
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The total number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_max_heap - Checks if a binary tree satisfies the max heap property
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree satisfies the max heap property, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
