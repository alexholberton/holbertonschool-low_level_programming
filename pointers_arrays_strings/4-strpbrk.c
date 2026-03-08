#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the string containing the characters to look for
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	/* On parcourt chaque caractère de la chaîne s */
	for (i = 0; s[i] != '\0'; i++)
	{
		/* Pour chaque caractère de s, on regarde s'il est dans accept */
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				/* Si match, on renvoie l'adresse actuelle de s[i] */
				return (s + i);
			}
		}
	}

	/* Si aucun caractère n'a été trouvé après les deux boucles */
	return (NULL);
}
