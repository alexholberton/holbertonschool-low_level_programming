#include <stdio.h>

/**
 * divide - Performs division of two numbers.
 * @a: The dividend.
 * @b: The divisor.
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

/**
 * main - Entry point for the simple calculator.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;
	float a, b;

	/* The prompt asks for Choice, A, and B input */
	if (scanf("%d", &choice) != 1)
		return (1);

	if (choice == 4)
	{
		if (scanf("%f %f", &a, &b) != 2)
			return (1);
		divide(a, b);
	}

	return (0);
}
