#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b);

/**
 * cocktail_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 * @list: the doubly linked list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	bool swapped = true;

	if (!list || (*list)->next == NULL)
		return;

	ptr = *list;
	while (swapped)
	{
		swapped = false;
		for ( ; ptr && ptr->next; ptr = ptr->next)
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(list, ptr, ptr->next);
				ptr = ptr->prev;
				swapped = true;
				print_list(*list);
			}

		if (!swapped)
			break;

		swapped = false;
		for ( ; ptr && ptr->prev; ptr = ptr->prev)
			if (ptr->prev->n > ptr->n)
			{
				swap_nodes(list, ptr->prev, ptr);
				ptr = ptr->next;
				swapped = true;
				print_list(*list);
			}
	}
}

/**
 * swap_nodes - a function that swaps two nodes of a doubly linked list.
 * It also knows to adjust head if it was swapped.
 * @list: the doubly linked list to sort.
 * @node_a: first node.
 * @node_b: second node.
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
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
		*list = node_b;
}
