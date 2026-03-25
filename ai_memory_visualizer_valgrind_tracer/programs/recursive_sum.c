#include <stdio.h>

int recursive_sum(int n)
{
	if (n <= 0)
		return 0;
	return n + recursive_sum(n - 1);
}

int main(void)
{
	int result = recursive_sum(3);
	printf("Sum: %d\n", result);
	return 0;
}

