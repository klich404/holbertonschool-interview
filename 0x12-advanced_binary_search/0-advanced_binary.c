#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints an array
 *
 * @array: array to print
 * @left: left bound
 * @right: right bound
 *
 * Return: void
 */

void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	for (; left <= right; left++)
	{
		printf("%i", array[left]);
		if (left < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - binary search
 *
 * @array: array to search
 * @left: left bound
 * @right: right bound
 * @value: value to search for
 *
 * Return: Index or -1
 */

int binary_search(int *array, size_t left, size_t right, int value)
{
	int mid;

	if (left < right)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;
		if (array[mid] >= value)
			return (binary_search(array, left, mid, value));
		return (binary_search(array, mid + 1, right, value));
	}
	if (array[left] == value)
		return (left);
	print_array(array, left, right);
	return (-1);
}

/**
 * advanced_binary - Finds index of first occurence of value
 *
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: Index of first occurence or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	int found;

	if (!array || size == 0)
		return (-1);
	found = binary_search(array, 0, size - 1, value);
	return (found);
}
