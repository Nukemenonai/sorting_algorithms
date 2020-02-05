#include "sort.h"

/**
 *insertion_sort_list - function that sort a double linke list
 *based in insertion sort
 *@list: double linked list to sort
 *
 *Return: nothing, it's a void function
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cpy_list, *save_prev_node, *test_node;

	if (!list || !(*list))
		return;
	cpy_list = *list;
	cpy_list = cpy_list->next;
	while (cpy_list != NULL)
	{
		test_node = cpy_list->prev;
		while (test_node != NULL && test_node->n > cpy_list->n)
		{
			save_prev_node = test_node->prev;
			test_node->next = cpy_list->next;
			test_node->prev = cpy_list;
			if (cpy_list->next != NULL)
				cpy_list->next->prev = test_node;
			cpy_list->next = test_node;
			cpy_list->prev = save_prev_node;
			if (save_prev_node != NULL)
				save_prev_node->next = cpy_list;
			else
				*list = cpy_list;
			test_node = cpy_list->prev;
			print_list(*list);
		}
		cpy_list = cpy_list->next;
	}
}
