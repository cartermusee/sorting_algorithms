#include "sort.h"

/**
 * swap - swaps 2 node
 * @n: address of first node
 * @k: address of second node
 */
void swap(listint_t *n, listint_t *k)
{
	if (n->prev)
		n->prev->next = k;
	if (k->next)
		k->next->prev = n;
	n->next = k->next;
	k->prev = n->prev;
	n->prev = k;
	k->next = n;

}

/**
 * insertion_sort_list - insertion sorts in doubly list
 * @list: address of pointer to node head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *n;

	if (!list || !*list || !(*list)->next)
		return;
	a = (*list)->next;
	while (a)
	{
		n = a;
		a = a->next;
		while (n && n->prev)
		{
			if (n->prev->n > n->n)
			{
				swap(n->prev, n);
				if (!n->prev)
					*list = n;
				print_list((const listint_t *)*list);
			}
			else
				n = n->prev;
		}

	}
}
