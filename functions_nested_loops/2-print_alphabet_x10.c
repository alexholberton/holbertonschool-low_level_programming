#include "main.h"

/**
* print_alphabet_x10 - Prints the alphabet in lowercase 10 times.
*
* Return: void
*/
void print_alphabet_x10(void)
{
	int count;

	char letter;

	for (count = 0; count < 10; count++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
		_putchar('\n');
	}
}
