#include "main.h"

/**
 * _puts2 - prints every other character of a string, followed by a new line
 * @str: pointer to the string to print
 *
 * Return: void
 */
void _puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');
}
