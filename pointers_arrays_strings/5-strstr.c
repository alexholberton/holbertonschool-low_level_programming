#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: the string to search in
 * @needle: the substring to look for
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	/* Si needle est vide, on renvoie haystack selon la norme standard */
	if (*needle == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		/* Si le premier caractère correspond, on vérifie la suite */
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			/* Si on a parcouru tout needle sans break, on a trouvé ! */
			if (needle[j] == '\0')
				return (haystack + i);
		}
	}

	return (NULL);
}
