#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid
 * Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_recursive(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_recursive - Recursive helper function to check if
 * a binary tree is a valid BST
 * @tree: Pointer to the current node being checked
 * @min: Minimum value constraint for the current node
 * @max: Maximum value constraint for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_recursive(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_recursive(tree->left, min, tree->n) &&
			is_bst_recursive(tree->right, tree->n, max));
}
