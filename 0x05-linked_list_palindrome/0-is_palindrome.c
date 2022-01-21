#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - function that checks if a singly linked list
 * is a palindrome.
 * @head: pointer to linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	return (checkPalindrome(head, *head));
}

/**
 * checkPalindrome - auxiliar function that checks if a singly linked
 * list is a palindrome.
 * @left: double pointer to linked list
 * @right: pointer to linked list
 * Return: 1 if it is a palindrome
 */
int checkPalindrome(listint_t **left, listint_t *right)
{
	if (right == NULL)
		return (1);

	int result = checkPalindrome(left, right->next) && ((*left)->n == right->n);
	(*left) = (*left)->next;

	return (result);
}
