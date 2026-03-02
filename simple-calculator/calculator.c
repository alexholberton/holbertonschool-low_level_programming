#include <stdio.h>

/**
 * main - entry point for the simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	int a, b;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			while (getchar() != '\n')
				;
			continue;
		}

		if (choice == 1)
		{
			/* Task 2: Addition Logic */
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
		else if (choice >= 2 && choice <= 4)
		{
			/* Placeholders for next tasks */
			continue;
		}
		else
		{
			printf("Invalid choice\n");
		}

	} while (choice != 0);

	return (0);
}
