#include <stdio.h>
#include "lists.h"

/**
 * print_list - Affiche tous les éléments d'une liste list_t.
 * @h: Pointeur vers le début de la liste (le premier noeud).
 *
 * Return: Le nombre total de noeuds dans la liste.
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}

		h = h->next;

		nodes++;
	}

	return (nodes);
}
