#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int a, z;

	for (a = array[0], z = 1; z < size; z++)
	{
		if (array[z] > a)
			a = array[z];
	}
	return (a);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int *x, *y, a, z;

	if (array == NULL || size < 2)
		return;

	y = malloc(sizeof(int) * size);
	if (y == NULL)
		return;
	a = get_max(array, size);
	x = malloc(sizeof(int) * (a + 1));
	if (x == NULL)
	{
		free(y);
		return;
	}

	for (z = 0; z < (a + 1); z++)
		x[z] = 0;
	for (z = 0; z < (int)size; z++)
		x[array[z]] += 1;
	for (z = 0; z < (a + 1); z++)
		x[z] += x[z - 1];
	print_array(x, a + 1);

	for (z = 0; z < (int)size; z++)
	{
		y[x[array[z]] - 1] = array[z];
		x[array[z]] -= 1;
	}

	for (z = 0; z < (int)size; z++)
		array[z] = y[z];

	free(y);
	free(x);
}
