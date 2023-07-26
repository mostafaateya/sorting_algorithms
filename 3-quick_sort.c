#include "sort.h"

void integer_swaping(int *x1, int *x2);
int mos_lpartition(int *array, size_t size, int left, int right);
void mos_lsort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * mos_lpartition - Order a subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */

int mos_lpartition(int *array, size_t size, int left, int right)
{
	int *a, x1, x2;

	a = array + right;
	for (x1 = x2 = left; x2 < right; x2++)
	{
		if (array[x2] < *a)
		{
			if (x1 < x2)
			{
				integer_swaping(array + x2, array + x1);
				print_array(array, size);
			}
			x1++;
		}
	}

	if (array[x1] > *a)
	{
		integer_swaping(array + x1, a);
		print_array(array, size);
	}

	return (x1);
}

/**
 * mos_lsort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Return: nothing
 */

void mos_lsort(int *array, size_t size, int left, int right)
{
	int a;

	if (right - left > 0)
	{
		a = mos_lpartition(array, size, left, right);
		mos_lsort(array, size, left, a - 1);
		mos_lsort(array, size, a + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	mos_lsort(array, size, 0, size - 1);
}
