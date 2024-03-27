#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1));
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: The starting index of the subarray
 * @end: The ending index of the subarray
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;

	avl_t *root = malloc(sizeof(avl_t));

	if (root == NULL)
		return (NULL);

	root->n = array[mid];
	root->left = build_avl_tree(array, start, mid - 1);
	root->right = build_avl_tree(array, mid + 1, end);

	return (root);
}
