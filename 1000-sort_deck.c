#include "deck.h"
#include <stdio.h>

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[z] - s2[z]
 */

int _strcmp(const char *s1, const char *s2)
{
	int z;

	z = 0;
	while (s1[z] != '\0' && s2[z] != '\0')
	{
		if (s1[z] != s2[z])
		{
			return (s1[z] - s2[z]);
		}
		z++;
	}
	return (0);
}

/**
 * card_positioning - return the position based on card you put in
 * @xx: represent the card
 * Return: return the card position
 */

int card_positioning(deck_node_t *xx)
{
	int out;

	out = (*xx).card->value[0] - '0';
	if (out < 50 || out > 57)
	{
		if (_strcmp((*xx).card->value, "Ace") == 1)
			out = 1;
		else if (_strcmp((*xx).card->value, "10") == 1)
			out = 10;
		else if (_strcmp((*xx).card->value, "Jack") == 1)
			out = 11;
		else if (_strcmp((*xx).card->value, "Queen") == 1)
			out = 12;
		else if (_strcmp((*xx).card->value, "King") == 1)
			out = 13;
	}
	out += (*xx).card->kind * 13;
	return (out);
}

/**
 *card_swaping - swap a card for his previous one
 *@card: card
 *@deck: card deck
 *Return: return a pointer to a card which was enter it
 */

deck_node_t *card_swaping(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * deck_sorting - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Dobule linked deck to sort
 */

void deck_sorting(deck_node_t **deck)
{
	int value_previous, value_current;
	deck_node_t *xx;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	xx = (*deck)->next;
	while (xx)
	{
		if (xx->prev)
		{
			value_previous = card_positioning((xx->prev));
			value_current = card_positioning(xx);
		}
		while ((xx->prev) && (value_previous > value_current))
		{
			value_previous = card_positioning((xx->prev));
			value_current = card_positioning(xx);
			xx = card_swaping(xx, deck);

		}
		xx = xx->next;
	}
}

/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 * Return: nothing
 */

void sort_deck(deck_node_t **deck)
{
	deck_sorting(deck);
}
