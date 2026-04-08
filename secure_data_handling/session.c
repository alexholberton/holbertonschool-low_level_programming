#include "secure_data.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_session - Creates a new session safely
 * @name: Name of the session to create
 *
 * Return: Pointer to the new session, or NULL if failure
 */
session_t *create_session(const char *name)
{
	session_t *new_node;

	if (!name)
		return (NULL);

	new_node = malloc(sizeof(session_t));
	if (!new_node)
		return (NULL);

	new_node->name = strdup(name);
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}

	new_node->id = 0;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_session - Frees a session and its allocated name
 * @session: Pointer to the session to free
 */
void free_session(session_t *session)
{
	if (!session)
		return;
	if (session->name)
		free(session->name);
	free(session);
}
