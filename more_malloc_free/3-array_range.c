#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the smallest value in the array
 * @max: the largest value in the array
 *
 * Return: pointer to the newly created array, or NULL if min > max or fails
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	array = malloc(sizeof(int) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		array[i] = min;
		min++;
	}

	return (array);
}
