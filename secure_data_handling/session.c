#include "secure_data.h"

/**
 * create_session - Allocates and initializes a new session
 * @name: Name of the session to be duplicated
 *
 * Return: Pointer to the new session, or NULL if allocation fails
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
 * free_session - Safely frees a session and its internal data
 * @session: Pointer to the session to be freed
 */
void free_session(session_t *session)
{
	if (!session)
		return;

	if (session->name)
		free(session->name);

	free(session);
}
