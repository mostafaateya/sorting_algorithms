#include "sort.h"

void integer_swaping(int *x1, int *x2);
void tree_to_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * integer_swaping - Swap two integers in an array.
 * @x1: The first integer to swap.
 * @x2: The second integer to swap.
 * Return: nothing
 */

void integer_swaping(int *x1, int *x2)
{
	int xx;

	xx = *x1;
	*x1 = *x2;
	*x2 = xx;
}

/**
 * tree_to_heap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 * Return: nothing
 */

void tree_to_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t a1, a2, len;

	a1 = 2 * root + 1;
	a2 = 2 * root + 2;
	len = root;

	if (a1 < base && array[a1] > array[len])
		len = a1;
	if (a2 < base && array[a2] > array[len])
		len = a2;

	if (len != root)
	{
		integer_swaping(array + root, array + len);
		print_array(array, size);
		tree_to_heap(array, size, base, len);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void heap_sort(int *array, size_t size)
{
	int z;

	if (array == NULL || size < 2)
		return;

	for (z = (size / 2) - 1; z >= 0; z--)
		tree_to_heap(array, size, size, z);

	for (z = size - 1; z > 0; z--)
	{
		integer_swaping(array, array + z);
		print_array(array, size);
		tree_to_heap(array, size, z, 0);
	}
}
