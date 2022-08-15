#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
	listint_t *key = *list;
	listint_t *temp;

	while(key->next)
	{
		if ((key->next != NULL) && (key->n > key->next->n))
		{
			swap(list, &key, &(key->next));
			print_list(*list);
			temp = key->prev;
			while (temp->prev)
			{
				printf("inside second while loop\n");
				if ((temp->prev != NULL) && (temp->n < temp->prev->n))
				{
					printf("inside if\n");
					swap(&(*list), &temp, &(temp->prev));
					print_list(*list);
				}
				temp = temp->prev;
			}
		}
		else
		{
			key = key->next;
		}
	}
}

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
	listint_t *previous = NULL, *next = NULL;

	if (temp1->prev)
	{
		previous = temp1->prev;
		previous->next = temp2;
	}
	temp2->prev = previous;
	if (temp2->next)
	{
		next = temp2->next;
		next->prev = temp1;
	}
	temp1->next = next;
	temp2->next = temp1;
	temp1->prev = temp2;
	
	if (temp1 == *head || temp2 == *head)
		*head = temp1->prev;
}
