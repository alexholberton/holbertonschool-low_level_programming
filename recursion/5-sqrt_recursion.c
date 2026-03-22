#include "main.h"

/**
 * find_sqrt - Fonction auxiliaire pour trouver la racine carrée.
 * @n: Le nombre dont on cherche la racine.
 * @i: Le candidat à tester.
 *
 * Return: La racine carrée ou -1.
 */
int find_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root, or -1 if it doesn't exist.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (find_sqrt(n, 0));
}
