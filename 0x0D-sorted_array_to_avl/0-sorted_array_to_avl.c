#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - AVL tree from sorted array
 *
 * @array: array to tree
 * @size: size of array to tree
 *
 * Return: Pointer to tree root
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rnode, *lnode, *node = NULL;
	size_t mid;

	if (size == 0 || !array)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL); /*FAILURE*/
	mid = (size - 1) / 2;
	node->n = array[mid];
	node->parent = NULL;
	if (mid > 0)
		lnode = sorted_array_to_avl(array, mid);
	else
		lnode = NULL;
	if (size > (mid + 1))
		rnode = sorted_array_to_avl(&array[mid + 1], size - (mid + 1));
	else
		rnode = NULL;
	node->left = lnode;
	node->right = rnode;
	if (node->left)
		(node->left)->parent = node;
	if (node->right)
		(node->right)->parent = node;
	return (node);
}
