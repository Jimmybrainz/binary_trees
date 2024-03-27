#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree where the node will be removed
 * @value: The value to remove from the tree
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *successor = bst_find_min(root->right);

		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}


/**
 * bst_find_min - Finds the minimum node in a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST
 *
 * Return: Pointer to the minimum node, or NULL if `root` is NULL
 */
bst_t *bst_find_min(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left != NULL)
		root = root->left;

	return (root);
}
