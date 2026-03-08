#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area to be filled
 * @b: the constant byte to fill the area with
 * @n: the number of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	/* On parcourt les n premiers octets de la zone mémoire */
	for (i = 0; i < n; i++)
	{
		/* On remplit chaque case avec l'octet b */
		s[i] = b;
	}

	/* Toujours retourner le pointeur d'origine */
	return (s);
}
