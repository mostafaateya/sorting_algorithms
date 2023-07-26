#include "sort.h"

void node_swaping_forward(listint_t **list, listint_t **tail, listint_t **n);
void node_swaping_backword(listint_t **list, listint_t **tail, listint_t **n);
void cocktail_sort_list(listint_t **list);

/**
 * node_swaping_forward - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @n: A pointer to the current swapping node of the cocktail n algo.
 * Return: nothing
 */

void node_swaping_forward(listint_t **list, listint_t **tail, listint_t **n)
{
	listint_t *xx = (*n)->next;

	if ((*n)->prev != NULL)
		(*n)->prev->next = xx;
	else
		*list = xx;
	xx->prev = (*n)->prev;
	(*n)->next = xx->next;
	if (xx->next != NULL)
		xx->next->prev = *n;
	else
		*tail = *n;
	(*n)->prev = xx;
	xx->next = *n;
	*n = xx;
}

/**
 * node_swaping_backword - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @n: A pointer to the current swapping node of the cocktail n algo.
 * Return: nothing
 */

void node_swaping_backword(listint_t **list, listint_t **tail, listint_t **n)
{
	listint_t *xx = (*n)->prev;

	if ((*n)->next != NULL)
		(*n)->next->prev = xx;
	else
		*tail = xx;
	xx->next = (*n)->next;
	(*n)->prev = xx->prev;
	if (xx->prev != NULL)
		xx->prev->next = *n;
	else
		*list = *n;
	(*n)->next = xx;
	xx->prev = *n;
	*n = xx;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail n algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *n;
	bool b = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (b == false)
	{
		b = true;
		for (n = *list; n != tail; n = n->next)
		{
			if (n->n > n->next->n)
			{
				node_swaping_forward(list, &tail, &n);
				print_list((const listint_t *)*list);
				b = false;
			}
		}
		for (n = n->prev; n != *list; n = n->prev)
		{
			if (n->n < n->prev->n)
			{
				node_swaping_backword(list, &tail, &n);
				print_list((const listint_t *)*list);
				b = false;
			}
		}
	}
}
