#include <stdio.h>

/**
 * main - Entry point of the calculator program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;

	int a, b, result;

	printf("Choice: ");
	scanf("%d", &choice);

	if (choice == 2)
	{
		printf("A: ");
		scanf("%d", &a);
		printf("B: ");
		scanf("%d", &b);

		result = a - b;

		printf("Result: %d\n", result);
	}

	return (0);
}
