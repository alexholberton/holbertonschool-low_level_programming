#include <stdio.h>

/**
* main - Entry point
* Description: prints all the numbers of base 16 in lowercase
* Return: Always 0 (Success)
*/
int main(void)
{
	int i = 0;
	char c = 'a';

	while (i < 10)
	{
		putchar(i + '0');
		i++;
	}
	while (c <= 'f')
	{
		putchar(c);
		c++;
	}
	putchar('\n');

	return (0);
}

