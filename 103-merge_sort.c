#include "sort.h"

void subarray_merging(int *, int *, size_t, size_t, size_t);
void sort_merging_rec(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * subarray_merging - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @a: The middle index of the array.
 * @back: The back index of the array.
 *Return: nothing
 */

void subarray_merging(int *subarr, int *buff,
		size_t front, size_t a, size_t back)
{
	size_t z1, z2, x = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, a - front);

	printf("[right]: ");
	print_array(subarr + a, back - a);

	for (z1 = front, z2 = a; z1 < a && z2 < back; x++)
		buff[x] = (subarr[z1] < subarr[z2]) ? subarr[z1++] : subarr[z2++];
	for (; z1 < a; z1++)
		buff[x++] = subarr[z1];
	for (; z2 < back; z2++)
		buff[x++] = subarr[z2];
	for (z1 = front, x = 0; z1 < back; z1++)
		subarr[z1] = buff[x++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * sort_merging_rec - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 * Return: nothing
 */

void sort_merging_rec(int *subarr, int *buff, size_t front, size_t back)
{
	size_t a;

	if (back - front > 1)
	{
		a = front + (back - front) / 2;
		sort_merging_rec(subarr, buff, front, a);
		sort_merging_rec(subarr, buff, a, back);
		subarray_merging(subarr, buff, front, a, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	sort_merging_rec(array, buff, 0, size);

	free(buff);
}
