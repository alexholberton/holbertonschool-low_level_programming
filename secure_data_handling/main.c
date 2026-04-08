#include "secure_data.h"

int main(void)
{
	session_t *store = NULL;
	session_t *new;
	session_t *found;

	printf("--- Test d'ajout ---\n");
	new = create_session("Session_Alpha");
	if (add_session_to_store(&store, new))
		printf("Ajouté : %s\n", new->name);

	new = create_session("Session_Beta");
	if (add_session_to_store(&store, new))
		printf("Ajouté : %s\n", new->name);

	printf("\n--- Test doublon (Session_Alpha) ---\n");
	new = create_session("Session_Alpha");
	if (!add_session_to_store(&store, new))
		printf("Succès : Le doublon a été rejeté et libéré.\n");

	printf("\n--- Test de recherche ---\n");
	found = find_session_by_name(store, "Session_Beta");
	if (found)
		printf("Trouvé : %s\n", found->name);
	else
		printf("Erreur : Session_Beta non trouvée.\n");

	printf("\n--- Nettoyage du store ---\n");
	clear_store(&store);
	if (store == NULL)
		printf("Le store est maintenant vide.\n");

	return (0);
}
