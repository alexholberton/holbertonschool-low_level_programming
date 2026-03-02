#include <stdio.h>

/**
 * main - entry point for the simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		/* Read user input */
		if (scanf("%d", &choice) != 1)
		{
			/* Clear buffer for non-numeric input to avoid infinite loop */
			while (getchar() != '\n')
				;
			continue;
		}

		/* Logic for menu choices */
		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice >= 1 && choice <= 4)
		{
			/* Operations will be added in the next tasks */
			continue;
		}
		else
		{
			/* Requirement: print "Invalid choice" for numbers not in menu */
			printf("Invalid choice\n");
		}

	} while (choice != 0);

	return (0);
}
