#include <stdio.h>
#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: skip list
 * @value: search value
 *
 * Return: Address of node of value or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skp = NULL;
	skiplist_t *hld = NULL;

	if (!list)
		return (NULL);
	skp = list;
	while (skp->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       (skp->express)->index, (skp->express)->n);
		if ((skp->express)->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       skp->index, (skp->express)->index);
			break;
		}
		if ((skp->express)->express == NULL)
		{
			skp = skp->express;
			hld = skp;
			while (hld->next)
				hld = hld->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       skp->index, hld->index);
			break;
		}
		skp = skp->express;
	}
	while (skp->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       skp->index, skp->n);
		if (skp->n == value)
			return (skp);
		if (skp->n > value)
			return (NULL);
		skp = skp->next;
	}
	printf("Value checked at index [%lu] = [%i]\n", skp->index, skp->n);
	return (NULL);
}
