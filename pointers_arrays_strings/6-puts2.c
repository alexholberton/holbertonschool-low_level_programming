#include "main.h"

/**
* _puts2 - prints every other character of a string
* @str: pointer to the string to print
*
* Return: void
*/
void _puts2(char *str)
{
	int i = 0;

	/* On vérifie que la chaîne n'est pas vide dès le début */
	while (str[i] != '\0')
	{
		_putchar(str[i]);

		/* On saute un caractère. Si on arrive au bout, on s'arrête. */
		if (str[i + 1] == '\0')
		{
			i++;
		}
		else
		{
			i += 2;
		}
	}
	_putchar('\n');
}
