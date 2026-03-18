#include "function_pointers.h"
#include <stdlib.h>

/**
* print_name - prints a name
* @name: name of the person
* @f: pointer to a function that takes a char * as argument and returns void
*
* Return: Nothing.
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
