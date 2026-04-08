#ifndef SECURE_DATA_H
#define SECURE_DATA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct session_s - Structure pour une session individuelle
 * @name: Nom de la session (alloué dynamiquement)
 * @id: Identifiant unique de la session
 * @next: Pointeur vers la session suivante (liste chaînée)
 */
typedef struct session_s
{
	char *name;
	int id;
	struct session_s *next;
} session_t;

/* --- Prototypes pour session.c --- */

session_t *create_session(const char *name);
void free_session(session_t *session);

/* --- Prototypes pour store.c --- */

int add_session_to_store(session_t **store, session_t *new_session);
session_t *find_session_by_name(session_t *store, const char *name);
void clear_store(session_t **store);

#endif
