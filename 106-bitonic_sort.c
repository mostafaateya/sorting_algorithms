#include "sort.h"

void integer_swaping(int *x1, int *x2);
void sorting_bitonic(int *array, size_t size,
		size_t start, size_t len, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t len, char flow);
void bitonic_sort(int *array, size_t size);

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
 * sorting_bitonic - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @len: The size of the sequence to sort.
 * @flow: The direction to sort in.
 * Return: nothing
 */

void sorting_bitonic(int *array, size_t size,
		size_t start, size_t len, char flow)
{
	size_t z, a = len / 2;

	if (len > 1)
	{
		for (z = start; z < start + a; z++)
		{
			if ((flow == MOS_UP && array[z] > array[z + a]) ||
			    (flow == MOS_DOWN && array[z] < array[z + a]))
				integer_swaping(array + z, array + z + a);
		}
		sorting_bitonic(array, size, start, a, flow);
		sorting_bitonic(array, size, start + a, a, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @len: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 * Return: nothing
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t len, char flow)
{
	size_t a = len / 2;
	char *str = (flow == MOS_UP) ? "UP" : "DOWN";

	if (len > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", len, size, str);
		print_array(array + start, len);

		bitonic_seq(array, size, start, a, MOS_UP);
		bitonic_seq(array, size, start + a, a, MOS_DOWN);
		sorting_bitonic(array, size, start, len, flow);

		printf("Result [%lu/%lu] (%s):\n", len, size, str);
		print_array(array + start, len);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, MOS_UP);
}
