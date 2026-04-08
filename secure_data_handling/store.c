#include "secure_data.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_session_to_store - Adds session and handles duplicates safely
 * @store: Pointer to head
 * @new_session: Session to add
 * Return: 1 on success, 0 on failure
 */
int add_session_to_store(session_t **store, session_t *new_session)
{
	session_t *check;

	if (!store || !new_session)
		return (0);

	/* Regardons si le nom existe déjà (Failure-Path Safety) */
	check = *store;
	while (check)
	{
		if (check->name && new_session->name &&
		    strcmp(check->name, new_session->name) == 0)
		{
			/* Doublon détecté : on libère pour éviter la fuite mémoire */
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
 * find_session_by_name - Search function
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
 * clear_store - Full cleanup for Valgrind compliance
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
