#ifndef SECURE_DATA_H
#define SECURE_DATA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct session_s - Session data structure
 * @name: Dynamically allocated string
 * @id: Session integer ID
 * @next: Pointer to the next node
 */
typedef struct session_s
{
	char *name;
	int id;
	struct session_s *next;
} session_t;

session_t *create_session(const char *name);
void free_session(session_t *session);
int add_session_to_store(session_t **store, session_t *new_session);
session_t *find_session_by_name(session_t *store, const char *name);
void clear_store(session_t **store);

#endif
