#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Description: This function checks if a binary tree is complete,
 * which means that all levels of the tree are completely
 * filled except possibly for the last level, which is
 * filled from left to right.
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the tree is complete using a helper function */
	return (is_complete_recursive(tree, 0, count_nodes(tree)));
}

/**
 * is_complete_recursive - Recursive helper function
 * @tree: Pointer to the current node being checked
 * @index: Index of the current node
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
			is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Total number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}
