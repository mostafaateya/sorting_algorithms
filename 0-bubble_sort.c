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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t z, a = size;
	bool b = false;

	if (array == NULL || size < 2)
		return;

	while (b == false)
	{
		b = true;
		for (z = 0; z < a - 1; z++)
		{
			if (array[z] > array[z + 1])
			{
				integer_swaping(array + z, array + z + 1);
				print_array(array, size);
				b = false;
			}
		}
		a--;
	}
}
