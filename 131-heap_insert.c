#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If the Heap is empty, make the new node the root */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Find the parent node for insertion */
	parent = find_insertion_parent(*root);

	/* Insert the new node as the left or right child of the parent */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Set the parent pointer of the new node */
	new_node->parent = parent;

	/* Restore the Max Heap ordering property */
	heapify_up(new_node);

	return (new_node);
}

/**
 * find_insertion_parent - Finds the parent node for
 * insertion in a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node for insertion
 */
heap_t *find_insertion_parent(heap_t *root)
{
	heap_t *parent;

	parent = root;

	/* Traverse the Heap to find the parent for insertion */
	while (parent->left != NULL && parent->right != NULL)
	{
		/* Choose the path with the least number of nodes */
		if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
			parent = parent->left;
		else
			parent = parent->right;
	}

	return (parent);
}

/**
 * heapify_up - Restores the Max Heap ordering property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	int temp;
	heap_t *parent;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		/* Swap node value with parent value */
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		parent = node->parent;
		node = parent;
	}
}
