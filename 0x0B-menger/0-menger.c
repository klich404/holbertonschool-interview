#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - 2d menger sponge print
 *
 * @level: levels of sponge
 *
 * Return: void
 */
void menger(int level)
{
	int size, x, y, dx, dy, f;

	size = (int)pow(3, level);
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			dx = x;
			dy = y;
			f = 0;
			while (dx && dy)
			{
				if (dx % 3 == 1 && dy % 3 == 1)
				{
					printf(" ");
					f = 1;
					break;
				}
				dx = dx / 3;
				dy = dy / 3;
			}
			if (!f)
				printf("#");
		}
		printf("\n");
	}
}
