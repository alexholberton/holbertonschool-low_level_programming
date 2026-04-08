#include "secure_data.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_session_to_store - Adds session and handles duplicates safely
 * @store: Double pointer to the head of the store
 * @new_session: Pointer to the session to add
 *
 * Return: 1 on success, 0 on failure
 */
int add_session_to_store(session_t **store, session_t *new_session)
{
	session_t *check;

	if (!store || !new_session)
		return (0);

	check = *store;
	while (check)
	{
		if (check->name && new_session->name &&
		    strcmp(check->name, new_session->name) == 0)
		{
			free_session(new_session);
			return (0);
		}
		check = check->next;
	}

	new_session->next = *store;
	*store = new_session;
	return (1);
}

/**
 * find_session_by_name - Search for a session by its name
 * @store: Pointer to the head of the store
 * @name: Name of the session to find
 *
 * Return: Pointer to the session found, or NULL if not found
 */
session_t *find_session_by_name(session_t *store, const char *name)
{
	if (!name)
		return (NULL);
	while (store)
	{
		if (store->name && strcmp(store->name, name) == 0)
			return (store);
		store = store->next;
	}
	return (NULL);
}

/**
 * clear_store - Frees all sessions in the store and sets head to NULL
 * @store: Double pointer to the head of the store
 */
void clear_store(session_t **store)
{
	session_t *tmp;

	if (!store || !*store)
		return;

	while (*store)
	{
		tmp = (*store)->next;
		free_session(*store);
		*store = tmp;
	}
	*store = NULL;
}
