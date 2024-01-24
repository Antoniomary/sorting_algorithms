#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: the doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *key, *ptr;

	if (!list || (*list)->next == NULL)
		return;

	unsorted = (*list)->next;
	while (unsorted)
	{
		key = unsorted;
		unsorted = unsorted->next;

		while (key->prev && key->prev->n > key->n)
		{
			ptr = key->prev;

			key->prev->next = key->next;
			if (key->next)
				key->next->prev = key->prev;
			else
				ptr->next = key->next;
			key->prev = ptr->prev;
			if (ptr->prev != NULL)
				ptr->prev->next = key;
			else
				*list = key;
			key->next = ptr;
			ptr->prev = key;
			print_list(*list);
		}
	}
}
