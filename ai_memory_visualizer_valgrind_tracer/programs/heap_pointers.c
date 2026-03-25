#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *a = malloc(sizeof(int));
	*a = 42;

	int *b = a;
	*b = 100;

	printf("a = %d, b = %d\n", *a, *b);

	free(a);
	a = NULL;

	return 0;
}

