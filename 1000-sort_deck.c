#include "deck.h"

void swap_nodes(deck_node_t **deck, deck_node_t *node_a, deck_node_t *node_b);
int value_n(deck_node_t *card);

/**
 * sort_deck - a function that sorts a deck of cards.
 * @deck: double pointer to the head node of the deck of cards.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *key, *sorted, *unsorted;

	if (!deck || *deck == NULL)
		return;

	unsorted = (*deck)->next;
	while (unsorted)
	{
		sorted = unsorted->prev;
		key = unsorted;
		unsorted = unsorted->next;

		while (sorted)
		{
			if (value_n(key) < value_n(sorted))
				swap_nodes(deck, sorted, key);
			sorted = sorted->prev;
		}
	}

	unsorted = (*deck)->next;
	while (unsorted)
	{
		sorted = unsorted->prev;
		key = unsorted;
		unsorted = unsorted->next;

		while (sorted)
		{
			if (key->card->kind < sorted->card->kind)
				swap_nodes(deck, sorted, key);
			sorted = sorted->prev;
		}
	}
}

/**
 * swap_nodes - a function that swaps two nodes of a doubly linked list.
 * It also knows to adjust head if it was swapped.
 * @deck: the doubly linked list to sort.
 * @node_a: first node.
 * @node_b: second node.
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node_a, deck_node_t *node_b)
{
	node_a->next = node_b->next;
	if (node_b->next)
		node_b->next->prev = node_a;
	node_b->prev = node_a->prev;
	if (node_a->prev)
		node_a->prev->next = node_b;
	node_a->prev = node_b;
	node_b->next = node_a;

	if (node_b->prev == NULL)
		*deck = node_b;
}

/**
 * value_n - a function that maps a string an integer.
 * @x: pointer to a struct holding the string.
 *
 * Return: an integer, n ==> {n: 0 <= n < 14}
 */
int value_n(deck_node_t *x)
{
	if (*x->card->value == 'A')
		return (0);
	if (*x->card->value == 'J')
		return (11);
	if (*x->card->value == 'Q')
		return (12);
	if (*x->card->value == 'K')
		return (13);
	if (*x->card->value == '1' && *(x->card->value + 1) == '0')
		return (10);
	return (*x->card->value - '0');
}
