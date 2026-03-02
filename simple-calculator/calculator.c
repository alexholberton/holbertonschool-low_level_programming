#include <stdio.h>

/**
 * main - entry point for the simple calculator program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;

	do {
		/* Display the menu */
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		/* Get user input */
		if (scanf("%d", &choice) != 1)
		{
			/* Clear the buffer if user enters a non-numeric value */
			while (getchar() != '\n')
				;
			printf("Invalid input. Please enter a number.\n");
			continue;
		}

		/* Process user choice */
		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice >= 1 && choice <= 4)
		{
			/* Logic for operations will be added in future tasks */
			printf("Operation %d selected\n", choice);
		}
		else
		{
			printf("Invalid choice, try again.\n");
		}

	} while (choice != 0);

	return (0);
}
