#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	/* On vérifie si on a bien 3 arguments : ./program, num1, num2 */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* Conversion des arguments de chaînes de caractères vers entiers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result);

	return (0);
}
