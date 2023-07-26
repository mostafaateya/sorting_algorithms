#include "sort.h"

void integer_swaping(int *x1, int *x2);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int a, x1, x2;

	a = array[right];
	for (x1 = left - 1, x2 = right + 1; x1 < x2;)
	{
		do {
			x1++;
		} while (array[x1] < a);
		do {
			x2--;
		} while (array[x2] > a);

		if (x1 < x2)
		{
			integer_swaping(array + x1, array + x2);
			print_array(array, size);
		}
	}

	return (x1);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Return: nothing
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int a;

	if (right - left > 0)
	{
		a = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, a - 1);
		hoare_sort(array, size, a, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
