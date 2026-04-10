#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Lit un fichier texte et l'affiche sur la sortie standard.
 * @filename: Nom du fichier à lire.
 * @letters: Nombre de lettres à lire et afficher.
 *
 * Return: Le nombre réel de lettres lues et affichées. 0 si erreur.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(fd);

	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}
