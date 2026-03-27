#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a linked list
 * @head: Pointer to the head of the list
 * @str: String to be added to the list
 *
 * Return: Address of the new node, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int length = 0;

	while (str[length])
		length++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	new->len = length;
	new->next = *head;
	*head = new;

	return (new);
}
