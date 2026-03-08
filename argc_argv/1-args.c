#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	/* On évite l'erreur "unused parameter" pour argv */
	(void)argv;

	/* On affiche argc - 1 car le nom du programme est inclus dans argc */
	printf("%d\n", argc - 1);

	return (0);
}
