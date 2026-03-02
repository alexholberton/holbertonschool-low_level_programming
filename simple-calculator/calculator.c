#include <stdio.h>

/**
 * main - entry point for the simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice = -1; /* Initialized to avoid 'uninitialized' error */
	int a, b;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		/* Capture input BEFORE checking conditions */
		if (scanf("%d", &choice) != 1)
		{
			/* Clear input buffer if user types a letter */
			while (getchar() != '\n')
				;
			continue;
		}

		if (choice == 1)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n", a + b);
		}
		else if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}

	} while (choice != 0);

	return (0);
}
