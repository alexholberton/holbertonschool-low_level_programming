#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	/* Si aucun argument (juste le nom du programme), on affiche 0 */
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	/* On parcourt chaque argument à partir de l'index 1 */
	for (i = 1; i < argc; i++)
	{
		/* On vérifie chaque caractère de l'argument actuel */
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			/* isdigit() vérifie si le caractère est un chiffre entre 0 et 9 */
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		/* Si tout est ok, on convertit et on ajoute à la somme */
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
