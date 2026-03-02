#include <stdio.h>

/**
* main - Simple calculator program
* Return: Always 0 (Success)
*/
int main(void)
{
	int choice;

	int a, b, result;

	if (choice == 3)
	{
		printf("A: ");
		if (scanf("%d", &a) != 1) return (1);
		printf("B: ");
		if (scanf("%d", &b) != 1) return (1);

		result = a * b;

		printf("Result: %d\n", result);
	}

	return (0);
}
