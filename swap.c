#include "sort.h"

/**
 * swap - swaps two elements of a listint_t list
 * @head: pointer to head node
 * @index1: pointer to first element to swap
 * @index2: pointer second element to swap
 *
 */

void swap(listint_t **head, listint_t **index1, listint_t **index2)
{
	int temp;
	listint_t *node1 = *index1;
	listint_t *node2 = *index2;
	listint_t *tempprev = node1->prev;
	listint_t *tempnext = node1->next;

	if (*head == node1)
		*head = node2;
	if (*head == node2)
		*head = node1;

	node1->prev = node2->prev;
	node1->next = node2->next;
	node2->prev = tempprev;
	node2->next = tempnext;
}
