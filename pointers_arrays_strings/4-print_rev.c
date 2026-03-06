#include "main.h"

/**
* print_rev - prints a string in reverse
* @s: pointer to the string to print
*
* Return: void
*/
void print_rev(char *s)

{
	int len = 0;

	int i;

	/* Calculer la longueur manuellement si _strlen n'est pas dispo */
	while (s[len] != '\0')
		len++;

	/* Affichage en sens inverse */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
