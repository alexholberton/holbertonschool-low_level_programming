#include "secure_data.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_session_to_store - Ajoute une session au stockage global
 * @store: Pointeur vers la tête de la liste de stockage
 * @new_session: La session à ajouter
 *
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int add_session_to_store(session_t **store, session_t *new_session)
{
	if (store == NULL || new_session == NULL)
		return (0);

	/* Insertion en tête de liste (rapide et sécurisé) */
	new_session->next = *store;
	*store = new_session;

	return (1);
}

/**
 * clear_store - Supprime et libère TOUTES les sessions du store
 * @store: Double pointeur vers la tête de liste
 *
 * Return: void
 */
void clear_store(session_t **store)
{
	session_t *current;
	session_t *next_node;

	if (store == NULL || *store == NULL)
		return;

	current = *store;

	while (current != NULL)
	{
		next_node = current->next;
		/* On utilise la fonction de libération sécurisée de session.c */
		free_session(current);
		current = next_node;
	}

	/* Crucial : on remet la tête de liste à NULL pour éviter les pointeurs fous */
	*store = NULL;
}

/**
 * find_session_by_name - Cherche une session sans risquer de crash
 * @store: La tête de liste
 * @name: Le nom recherché
 *
 * Return: Pointeur vers la session ou NULL
 */
session_t *find_session_by_name(session_t *store, const char *name)
{
	if (name == NULL)
		return (NULL);

	while (store != NULL)
	{
		if (store->name != NULL && strcmp(store->name, name) == 0)
			return (store);
		store = store->next;
	}

	return (NULL);
}
