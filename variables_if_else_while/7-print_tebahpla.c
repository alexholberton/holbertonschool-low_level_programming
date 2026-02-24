#include <stdio.h>

/**
* main - Point d'entrée
* Description: prints the lowercase alphabet in reverse
* Return: Toujours 0 (Succès)
*/
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');

	return (0);
}
