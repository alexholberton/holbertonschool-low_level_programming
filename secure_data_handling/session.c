#include "secure_data.h" /* Assure-toi que le nom du header correspond au tien */
#include <stdlib.h>
#include <string.h>

/**
 * create_session - Crée une nouvelle session de manière sécurisée
 * @name: Le nom de la session à copier
 *
 * Return: Un pointeur vers la nouvelle session, ou NULL en cas d'échec
 */
session_t *create_session(const char *name)
{
	session_t *new_session;

	if (name == NULL || *name == '\0')
		return (NULL);

	/* 1. Allocation de la structure avec vérification */
	new_session = malloc(sizeof(session_t));
	if (new_session == NULL)
		return (NULL);

	/* 2. Copie sécurisée du nom (évite les buffer overflows) */
	new_session->name = strdup(name);
	if (new_session->name == NULL)
	{
		free(new_session);
		return (NULL);
	}

	/* 3. Initialisation des autres membres pour éviter la "mémoire sale" */
	new_session->id = 0; /* Ou une logique d'ID spécifique */
	new_session->data = NULL;
	new_session->next = NULL;

	return (new_session);
}

/**
 * free_session - Libère proprement toute la mémoire d'une session
 * @session: La session à supprimer
 *
 * Return: void
 */
void free_session(session_t *session)
{
	if (session == NULL)
		return;

	/* On libère d'abord ce qui est à l'intérieur (le nom dupliqué) */
	if (session->name != NULL)
		free(session->name);

	/* On peut aussi libérer session->data si c'est alloué dynamiquement */

	/* Enfin, on libère la structure elle-même */
	free(session);
}
