#include "main.h"

/**
 * check_prime - Vérifie récursivement si n a des diviseurs.
 * @n: Le nombre à vérifier.
 * @i: Le diviseur actuel à tester.
 *
 * Return: 1 si premier, 0 sinon.
 */
int check_prime(int n, int i)
{
	if (i == n)
		return (1);

	if (n % i == 0)
		return (0);

	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - States if a number is a prime number.
 * @n: The number to check.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (check_prime(n, 2));
}
