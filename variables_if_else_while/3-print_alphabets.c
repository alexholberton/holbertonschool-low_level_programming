#include <stdio.h>

/**
	* main - Entry point
	* Description: Print the alphabet in lowercase and uppercase
	* Return: Always 0 (Success)
	*/

int main(void)
{
	char c = 'a';
	char d = 'A';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	d = 'A';
	while (d <= 'Z')
	{
		putchar(d);
		d++;
	}
	putchar('\n');

	return (0);
}
