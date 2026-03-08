#include <stdio.h>

/**
 * main - prints all arguments it receives
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	/* On boucle de 0 jusqu'à argc - 1 */
	for (i = 0; i < argc; i++)
	{
		/* On affiche l'argument situé à l'index i */
		printf("%s\n", argv[i]);
	}

	return (0);
}
