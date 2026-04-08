#include "secure_data.h"

/**
 * add_session_to_store - Adds session and handles duplicates safely
 * @store: Double pointer to the head of the session list
 * @new_session: Pointer to the new session to be added
 *
 * Return: 1 on success, 0 on failure or if duplicate exists
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
 * find_session_by_name - Search for a session in the store by name
 * @store: Pointer to the head of the session list
 * @name: String representing the name to search for
 *
 * Return: Pointer to the found session, or NULL if not found
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
 * clear_store - Frees all sessions in the store and resets head to NULL
 * @store: Double pointer to the head of the session list
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
