#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to search
 * @accept: the string containing the characters to match
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;
	unsigned int count = 0;
	int found;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;
		/* On vérifie si le caractère actuel de s est dans accept */
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				found = 1;
				break;
			}
		}
		/* Si on ne trouve pas le caractère dans accept, on s'arrête */
		if (found == 0)
		{
			return (count);
		}
	}

	return (count);
}
