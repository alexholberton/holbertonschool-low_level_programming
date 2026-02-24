#include <stdio.h>

/**
* main - Point d'entrée
* Description: affiche l'alphabet en minuscules sauf q et e
* Return: Toujours 0 (Succès)
*/
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		if (c != 'e' && c != 'q')
		{
			putchar(c);
		}
		c++;
	}
	putchar('\n');

	return (0);
}
