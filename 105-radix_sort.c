#include "sort.h"

int get_max(int *array, int size);
void sort_counting_radix(int *array, size_t size, int aa, int *buff);
void radix_sort(int *array, size_t size);

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
 * sort_counting_radix - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @aa: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 * Return: nothing
 */

void sort_counting_radix(int *array, size_t size, int aa, int *buff)
{
	int ll[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t z;

	for (z = 0; z < size; z++)
		ll[(array[z] / aa) % 10] += 1;

	for (z = 0; z < 10; z++)
		ll[z] += ll[z - 1];

	for (z = size - 1; (int)z >= 0; z--)
	{
		buff[ll[(array[z] / aa) % 10] - 1] = array[z];
		ll[(array[z] / aa) % 10] -= 1;
	}

	for (z = 0; z < size; z++)
		array[z] = buff[z];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
	int a, z, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	a = get_max(array, size);
	for (z = 1; a / z > 0; z *= 10)
	{
		sort_counting_radix(array, size, z, buff);
		print_array(array, size);
	}

	free(buff);
}
