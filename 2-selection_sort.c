#include "sort.h"

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
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	int *a;
	size_t z1, z2;

	if (array == NULL || size < 2)
		return;

	for (z1 = 0; z1 < size - 1; z1++)
	{
		a = array + z1;
		for (z2 = z1 + 1; z2 < size; z2++)
			a = (array[z2] < *a) ? (array + z2) : a;

		if ((array + z1) != a)
		{
			integer_swaping(array + z1, a);
			print_array(array, size);
		}
	}
}
