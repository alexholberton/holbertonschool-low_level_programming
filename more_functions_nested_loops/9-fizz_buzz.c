#include "main.h"
/**
* print_number - prints a number
* @n: number to print
*/
void print_number(int n)
{
	_putchar(n / 10 + '0');
	_putchar(n % 10 + '0');
}

/**
* print_fizz_buzz - prints the numbers from 1 to 100, followed by a new line
*
*/
void print_fizz_buzz(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
		{
			_putchar('F');
			_putchar('i');
			_putchar('z');
			_putchar('z');
			_putchar('B');
			_putchar('u');
			_putchar('z');
			_putchar('z');
		}
		else if (i % 3 == 0)
		{
			_putchar('F');
			_putchar('i');
			_putchar('z');
			_putchar('z');
		}
		else if (i % 5 == 0)
		{
			_putchar('B');
			_putchar('u');
			_putchar('z');
			_putchar('z');
		}
		else
		{
			print_number(i);
		}
		if (i < 100)
		{
			_putchar(',');
			_putchar(' ');
		}
	}
	_putchar('\n');
}
