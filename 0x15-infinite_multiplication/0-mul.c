#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * error - error printing/handling
 *
 * Return: 98
 */

int error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _strlen - length of string
 * @str: str to len
 *
 * Return: length
 */

int _strlen(char *str)
{
	int count = 0;

	while (*(str + count) != 0)
		count++;
	return (count);
}

/**
 * memeset - not memset
 * @a: mem address
 * @c: set type
 * @size: size
 *
 * Return: pointer
 */

void *memeset(void *a, int c, int size)
{
	int i;
	unsigned char *p = a;

	for (i = 0 ; i < size ; i++)
	{
		*p = c;
		p++;
	}
	return (a);
}

/**
 * _calloc - calloc
 * @nmemb: elements
 * @size: bytes
 *
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *areigh;

	if (size && nmemb)
	{
		areigh = malloc(nmemb * size);
		if (areigh)
		{
			memeset(areigh, '\0', nmemb * size);
			return (areigh);
		}
	}
	return (NULL);
}

/**
 * ar_fill - converts char argv into int array
 * @args: char argv
 * @arr: array to fill
 * @len: length of argv array
 *
 * Return: void
 */

void ar_fill(char *args, int *arr, int len)
{
	int idx = len;
	char arg;

	while (idx > 0)
	{
		arg = args[idx - 1];
		if (!(arg >= 48 && arg <= 57))
			error();
		arr[idx - 1] = arg - 48;
		idx--;
	}
}

/**
 * put_ar - putchars an int array, ignores leading zeroes
 * @arr: array to put
 * @len: length of array
 *
 * Return: void
 */

void put_ar(int *arr, int len)
{
	int idx = 0, zflag = 0;

	for (; idx < len; idx++)
	{
		if (arr[idx] != 0 || zflag == 1)
		{
			_putchar(arr[idx] + 48);
			zflag = 1;
		}
	}
	_putchar('\n');
}

/**
 * ar_times - multiplies an int in array form by an int
 * @arr2: int in array form to be multiplied
 * @mul: int to multiply
 * @len2: length of int array
 * @len3: length of result array
 *
 * Return: result array pointer
 */

int *ar_times(int *arr2, int mul, int len2, int len3)
{
	int *arr4 = NULL, res, idx2 = len2, idx4 = len3;

	arr4 = _calloc(len3, sizeof(int));
	if (!arr4)
		error();
	for (; idx2 > 0; idx2--)
	{
		res = mul * arr2[idx2 - 1];
		arr4[idx4 - 1] += res;
		if (arr4[idx4 - 1] > 9)
		{
			arr4[idx4 - 2] += (arr4[idx4 - 1] / 10);
			arr4[idx4 - 1] %= 10;
		}
		idx4--;
	}
	return (arr4);
}

/**
 * ar_add - Adds two ints in array form
 * @arr3: array to add into
 * @arr4: array to add from
 * @len3: length of both arrays
 * @tens: trailing zeroes place
 *
 * Return: void
 */

void ar_add(int *arr3, int *arr4, int len3, int tens)
{
	int idx3 = len3;

	for (; idx3 > 1 + tens; idx3--)
	{
		arr3[idx3 - 1 - tens] += arr4[idx3 - 1];
		if (arr3[idx3 - 1 - tens] > 9)
		{
			arr3[idx3 - 2 - tens] += (arr3[idx3 - 1 - tens] / 10);
			arr3[idx3 - 1 - tens] %= 10;
		}
	}
}

/**
 * ar_mul - multiplies two ints in array form
 * @arr1: first int in array form
 * @arr2: second int in array form
 * @arr3: result array
 * @len1: length of first array
 * @len2: length of second array
 * @len3: length of result array
 *
 * Return: void
 */

void ar_mul(int *arr1, int *arr2, int *arr3, int len1, int len2, int len3)
{
	int idx1 = len1, tens = 0;
	int *arr4 = NULL;

	for (; idx1 > 0; idx1--)
	{
		arr4 = ar_times(arr2, arr1[idx1 - 1], len2, len3);
		ar_add(arr3, arr4, len3, tens);
		free(arr4);
		tens++;
	}
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 or 98
 */

int main(int argc, char *argv[])
{
	int len1, len2, len3;
	int *arr1 = NULL, *arr2 = NULL, *arr3 = NULL;

	if (argc != 3)
		error();
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len3 = len1 + len2 + 2;

	arr1 = _calloc(len1, sizeof(int));
	arr2 = _calloc(len2, sizeof(int));
	arr3 = _calloc(len3, sizeof(int));
	if (!arr1 || !arr2 || !arr3)
		error();

	ar_fill(argv[1], arr1, len1);
	ar_fill(argv[2], arr2, len2);

	ar_mul(arr1, arr2, arr3, len1, len2, len3);

	put_ar(arr3, len3);

	free(arr1);
	free(arr2);
	free(arr3);
	return (0);
}
