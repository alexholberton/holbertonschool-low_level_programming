#include "main.h"

/**
* swap_ints - swaps the values of two integers
* @a: pointer to the first integer
* @b: pointer to the second integer
*
* Return: void
*/
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
