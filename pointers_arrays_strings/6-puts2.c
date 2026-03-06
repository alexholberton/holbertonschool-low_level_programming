#include "main.h"

/**
 * puts2 - prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str: The string to be treated.
 *
 * Return: void.
 */
void puts2(char *str)
{
	int i = 0;

	/* On parcourt la chaîne caractère par caractère */
	while (str[i] != '\0')
	{
		/* On affiche le caractère actuel */
		_putchar(str[i]);

		/* On avance de 1 */
		i++;

		/* Si on n'est pas à la fin, on saute le caractère suivant */
		if (str[i] != '\0')
		{
			i++;
		}
		/* Si on était déjà à la fin (\0), la boucle s'arrêtera */
		/* au prochain test */
	}
	_putchar('\n');
}
