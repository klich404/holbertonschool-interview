#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert node into sorted linked list
 *
 * @head: head of sorted linked list
 * @number: number to insert into sorted linked list
 *
 * Return: Address of new node or NULL on failure
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *strider;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	strider = *head;
	if (number < strider->n)
	{
		new->next = strider;
		*head = new;
		return (new);
	}
	while (strider->next && number > strider->next->n)
	{
		strider = strider->next;
	}
	new->next = strider->next;
	strider->next = new;
	return (new);
}
