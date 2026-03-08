#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the start of the matrix (cast as a linear array)
 * @size: the width/height of the matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		/* Diagonale principale : (0,0), (1,1), (2,2)... */
		/* Formule : i * size + i */
		sum1 += a[i * size + i];

		/* Diagonale secondaire : (0, size-1), (1, size-2)... */
		/* Formule : i * size + (size - 1 - i) */
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", sum1, sum2);
}
