#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Ajoute du texte à la fin d'un fichier existant.
 * @filename: Nom du fichier.
 * @text_content: Chaîne de caractères à ajouter (terminée par NULL).
 *
 * Return: 1 en cas de succès, -1 en cas d'échec.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	/* 1. Ouvrir le fichier en mode écriture seule et APPEND */
	/* Note : On ne met pas de permissions (0600) car on ne crée pas le fichier */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* 2. Si text_content est NULL, on a juste vérifié que le fichier existe */
	if (text_content != NULL)
	{
		/* Calcul de la longueur de la chaîne */
		while (text_content[len])
			len++;

		/* 3. Écrire à la fin du fichier */
		bytes_written = write(fd, text_content, len);
		if (bytes_written == -1 || bytes_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
