#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: 2D array representing the board
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int row, col;

	/* On boucle sur les 8 lignes */
	for (row = 0; row < 8; row++)
	{
		/* On boucle sur les 8 colonnes de chaque ligne */
		for (col = 0; col < 8; col++)
		{
			_putchar(a[row][col]);
		}
		/* Nouvelle ligne après chaque rangée de l'échiquier */
		_putchar('\n');
	}
}
