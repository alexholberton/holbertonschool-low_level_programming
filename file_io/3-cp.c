#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_fd - Ferme un descripteur de fichier et gère l'erreur.
 * @fd: Le descripteur de fichier à fermer.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copie le contenu d'un fichier vers un autre.
 * @ac: Nombre d'arguments.
 * @av: Tableau des arguments.
 *
 * Return: 0 en cas de succès.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t n_read, n_written;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close_fd(fd_from);
		exit(99);
	}
	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_written = write(fd_to, buffer, n_read);
		if (n_written == -1 || n_written != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
