#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 * Return: nothing
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *a, *s, *xx;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (a = (*list)->next; a != NULL; a = xx)
	{
		xx = a->next;
		s = a->prev;

		while (s != NULL && a->n < s->n)
		{
			swap_nodes(list, &s, a);
			print_list((const listint_t *)*list);
		}
	}
}
