#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * create_file - Crée un fichier et y écrit du texte.
 * @filename: Nom du fichier à créer.
 * @text_content: Chaîne de caractères à écrire.
 *
 * Return: 1 en cas de succès, -1 en cas d'échec.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	/* 1. Ouvrir avec O_CREAT (créer) et O_TRUNC (écraser) */
	/* Le mode 0600 correspond à rw------- */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* 2. Si text_content n'est pas NULL, on calcule sa longueur */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;

		/* 3. Écrire le contenu */
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
