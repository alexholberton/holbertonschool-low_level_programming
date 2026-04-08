#include "secure_data.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_session - Creates a new session safely
 * @name: Name of the session
 * Return: Pointer to session or NULL
 */
session_t *create_session(const char *name)
{
	session_t *new;

	if (!name)
		return (NULL);

	new = malloc(sizeof(session_t));
	if (!new)
		return (NULL);

	new->name = strdup(name);
	if (!new->name)
	{
		free(new);
		return (NULL);
	}

	new->id = 0;
	new->next = NULL;
	return (new);
}

/**
 * free_session - Frees all memory associated with a session
 * @session: Session to free
 */
void free_session(session_t *session)
{
	if (!session)
		return;
	if (session->name)
		free(session->name);
	free(session);
}
