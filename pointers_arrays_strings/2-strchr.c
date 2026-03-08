#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: the string to be searched
 * @c: the character to find
 *
 * Return: a pointer to the first occurrence of c,
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	/* On parcourt la chaîne, y compris le caractère nul final \0 */
	for (i = 0; s[i] >= '\0'; i++)
	{
		/* Si on trouve le caractère, on renvoie l'adresse actuelle */
		if (s[i] == c)
		{
			return (s + i);
		}
		/* Si on arrive au bout sans avoir trouvé c, on arrête */
		if (s[i] == '\0')
		{
			break;
		}
	}

	return (NULL);
}
