#include <stdio.h>

int	main(void)
{
	int			Q;
	long int	a[100];
	int 		k[100];

	scanf("%d", &Q);
	// printf("%d\n",Q);

	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < 40; i++)
		a[i] = a[i - 2] + a[i - 1];
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &k[i]);
		printf("%ld\n", a[k[i] - 1]);
	}
	return (0);
}