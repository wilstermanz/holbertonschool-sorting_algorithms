#include "sort.h"

/**
 * swap - swaps two adjacent elements of a listint_t list
 * @head: pointer to head
 * @node1: pointer to first adjacent node
 * @node2: pointer to second adjacent node
 */

void swap(listint_t **head, listint_t **node1, listint_t **node2)
{
	listint_t *temp1 = *node1;
	listint_t *temp2 = *node2;

	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp1;
	if (temp1->next)
	{
		temp2 = temp1->next;
		temp2->prev = temp1;
	}
	if (temp1 == *head || temp2 == *head)
		*head = temp1->prev;
}
