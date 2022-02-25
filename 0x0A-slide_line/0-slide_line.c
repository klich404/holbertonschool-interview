#include <stdlib.h>
#include "slide_line.h"

/**
 * slidel - Slide left
 *
 * @line: array to slide left
 * @size: size of array
 *
 * Return: 1 on success, 0 otherwise
 */

int slidel(int *line, size_t size)
{
	size_t sr = 0;
	size_t sl = 0;
	int hold = 0;

	for (; sr < size; sr++)
	{
		if (line[sr] == 0)
			continue;
		if (hold == 0)
			hold = line[sr];
		else if (hold == line[sr])
		{
			line[sl] = hold + line[sr];
			hold = 0;
			sl++;
		}
		else
		{
			line[sl] = hold;
			hold = line[sr];
			sl++;
		}
	}
	if (hold)
	{
		line[sl] = hold;
		sl++;
	}
	for (; sl < sr; sl++)
		line[sl] = 0;
	return (1);
}

/**
 * slider - Slide right
 *
 * @line: array to slide left
 * @size: size of array
 *
 * Return: 1 on success, 0 otherwise
 */

int slider(int *line, size_t size)
{
	size_t sr = size;
	size_t sl = size;
	int hold = 0;

	for (; sl > 0; sl--)
	{
		if (line[sl - 1] == 0)
			continue;
		if (hold == 0)
			hold = line[sl - 1];
		else if (hold == line[sl - 1])
		{
			line[sr - 1] = hold + line[sl - 1];
			hold = 0;
			sr--;
		}
		else
		{
			line[sr - 1] = hold;
			hold = line[sl - 1];
			sr--;
		}
	}
	if (hold)
	{
		line[sr - 1] = hold;
		sr--;
	}
	for (; sl < sr; sr--)
		line[sr - 1] = 0;
	return (1);
}

/**
 * slide_line - Slides an integer array
 *
 * @line: integer array to slide
 * @size: size of integer line
 * @direction: direction to slide integer array
 *
 * Return: 1 upon success, 0 otherwise
 */

int slide_line(int *line, size_t size, int direction)
{
	int output = 0;

	if (direction == -1)
		output = slidel(line, size);
	else if (direction == 1)
		output = slider(line, size);
	return (output);
}
