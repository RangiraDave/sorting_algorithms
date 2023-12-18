#include "sort.h"

/**
 * insertion_sort_list - Function to implement insertion
 * sort for doubly linked list.
 * @list: Pointer to head of the list.
 * Return: Nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;
			print_list(*list);
		}

		current = next;
	}
}
