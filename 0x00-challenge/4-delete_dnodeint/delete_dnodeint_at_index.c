#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	tmp = *head;
	p = 0;
	while (p < index && tmp->next)
	{
		tmp = tmp->next;
		p++;
	}
	if (p == index && tmp)
	{
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		else
			*head = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (-1);
}
