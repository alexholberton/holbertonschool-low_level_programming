#include <stdio.h>

/**
 * divide - Performs division of two numbers.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: void. Prints "Error: division by zero" if b is 0,
 * otherwise prints the result as a float for precision.
 */
void divide(float a, float b)
{
	if (b == 0)
	{
		printf("Error: division by zero\n");
	}
	else
	{
		float result = a / b;
		/* Using %.1f to match the expected '2.5' output format */
		printf("Result: %.1f\n", result);
	}
}
