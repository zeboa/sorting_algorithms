#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to a list of array
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp_1, *temp_2;
	listint_t *node_a, *node_b;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		node_b = current;
		node_a = current->prev;
		while (node_a != NULL && node_b->n < node_a->n)
		{
			temp_1 = node_a->prev;
			temp_2 = node_b->next;
			if (node_a->prev)
				temp_1->next = node_b;
			else
				*list = node_b;
			if (node_b->next)
				temp_2->prev = node_a;
			node_a->prev = node_b;
			node_a->next = temp_2;
			node_b->prev = temp_1;
			node_b->next = node_a;
			node_a = node_b->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
