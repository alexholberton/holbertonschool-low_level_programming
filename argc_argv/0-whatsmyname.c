#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of arguments (unused)
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	/* On empêche l'avertissement "unused parameter" pour argc */
	(void)argc;

	/* Le nom du programme est toujours dans argv[0] */
	printf("%s\n", argv[0]);

	return (0);
}
