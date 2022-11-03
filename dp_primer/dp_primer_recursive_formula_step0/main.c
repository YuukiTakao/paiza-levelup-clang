#include <stdio.h>

int	main(void)
{
	int	x, d, k;
	int a[1000];
	/*
	a[1] <- x

	for i = 2 to k
		a[i] <- a[i-1] + d

	print a[k]
	*/

	scanf("%d %d %d", &x, &d, &k);
	// printf("%d %d %d", x, d, k);

	a[0] = x;
	for (int i = 1; i < k; i++)
	{
		a[i] = a[i - 1] + d;
	}
	printf("%d", a[k - 1]);
	return (0);
}