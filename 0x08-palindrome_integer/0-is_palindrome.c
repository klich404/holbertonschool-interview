#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given
 * unsigned integer is a palindrome
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int num_rev = 0, mod, num;

	num = n;

	while (n != 0)
	{
		mod = n % 10;
		num_rev = num_rev * 10 + mod;
		n /= 10;
	}

	if (num == num_rev)
		return (1);

	return (0);
}
