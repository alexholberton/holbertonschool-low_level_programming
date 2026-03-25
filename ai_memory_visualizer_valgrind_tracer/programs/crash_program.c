#include <stdio.h>
#include <stdlib.h>

int *get_value(void)
{
	int local = 42;
	return &local;
}

int main(void)
{
	int *p = get_value();
	printf("value = %d\n", *p);

	int *q = NULL;
	*q = 10;

	return 0;
}

