#include <stdlib.h>
#include "binary_trees.h"

/**
 * last_node - finds last node of a binary heap
 *
 * @root: pointer to root of heap
 *
 * Return: pointer to last node or NULL
 */

binary_tree_t *last_node(binary_tree_t *root)
{
	binary_tree_t *queue[100];
	binary_tree_t *strider = root;
	int enter = 0, exit = 0;

	if (!strider)
		return (NULL);
	while (strider->left && strider->right)
	{
		queue[enter] = strider->left;
		enter += 1;
		if (enter >= 99)
			enter = 0;
		queue[enter] = strider->right;
		enter += 1;
		if (enter >= 99)
			enter = 0;
		strider = queue[exit];
		exit += 1;
		if (exit >= 99)
			exit = 0;
	}
	if (strider->left)
		return (strider->left);
	if (exit == 0)
		return (queue[98]->right);
	return (queue[exit - 1]->right);
}

/**
 * sink_down - sinks down a binary heap
 *
 * @root: root of heap
 *
 * Return: void
 */

void sink_down(binary_tree_t *root)
{
	binary_tree_t *sink = root;
	int left, right;

	while (sink->left)
	{
		left = (sink->left)->n;
		if (sink->right)
		{
			right = (sink->right)->n;
			if (sink->n >= left && sink->n >= right)
				break;
			if (right > left)
			{
				(sink->right)->n = sink->n;
				sink->n = right;
				sink = sink->right;
			}
			else
			{
				(sink->left)->n = sink->n;
				sink->n = left;
				sink = sink->left;
			}
		}
		else
		{
			if (sink->n >= left)
				break;
			(sink->left)->n = sink->n;
			sink->n = left;
		}
	}

}


/**
 * heap_extract - extract root node of a binary heap
 *
 * @root: root of binary heap
 *
 * Return: Value of root or 0
 */

int heap_extract(binary_tree_t **root)
{
	binary_tree_t *xtract = NULL, *move = NULL;
	int temp;

	if (!root || !*root)
		return (0);
	xtract = *root;
	move = last_node(*root);
	if (move->parent)
	{
		if ((move->parent)->right)
			(move->parent)->right = NULL;
		else
			(move->parent)->left = NULL;
		move->parent = NULL;
	}
	move->left = xtract->left;
	move->right = xtract->right;
	*root = move;
	sink_down(move);
	temp = xtract->n;
	free(xtract);
	return (temp);
}
