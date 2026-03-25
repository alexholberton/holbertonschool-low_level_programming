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

	/* Bug 1: use-after-free via dangling pointer b */
	printf("b after free = %d\n", *b);

	/* Bug 2: memory leak - allocate without freeing */
	int *c = malloc(sizeof(int) * 10);
	c[0] = 1;

	return 0;
}

