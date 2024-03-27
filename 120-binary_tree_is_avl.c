#include "binary_trees.h"

/**
 * avl_helper - Helper function to check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int avl_helper(const binary_tree_t *tree)
{
	int ltree_h, rtree_h;

	if (tree == NULL)
		return (1);

	if (binary_tree_is_bst(tree) == 0)
		return (0);

	ltree_h = binary_tree_height(tree->left);
	rtree_h = binary_tree_height(tree->right);

	if (abs(ltree_h - rtree_h) > 1)
		return (0);
	else
		return (avl_helper(tree->left) && avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_bst(tree) == 0)
		return (0);

	return (avl_helper(tree));
}


/**
 * bst_helper - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value allowed in the subtree
 * @max: The maximum value allowed in the subtree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_helper(tree->left, min, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}


/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: returns height of tree/subtree; if tree is NULL, return 0
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = right_height = 0;
	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 1;

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 1;

	if (left_height >= right_height)
		return (left_height);
	else
		return (right_height);
}
