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
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t a, z1, z2;

	if (array == NULL || size < 2)
		return;
	for (a = 1; a < (size / 3);)
		a = a * 3 + 1;
	for (; a >= 1; a /= 3)
	{
		for (z1 = a; z1 < size; z1++)
		{
			z2 = z1;
			while (z2 >= a && array[z2 - a] > array[z2])
			{
				integer_swaping(array + z2, array + (z2 - a));
				z2 -= a;
			}
		}
		print_array(array, size);
	}
}
