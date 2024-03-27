#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	/* Insert elements into the Heap one by one */
	for (i = 0; i < size; i++)
	{
		if (heap_insert(&root, array[i]) == NULL)
			return (NULL);
	}

	return (root);
}
