#include <stdio.h>

int	main(void)
{
	int			x, d_1, d_2, Q;
	long int	a[1009];
	long int	k[1009];
	
	scanf("%d %d %d %d", &x,&d_1,&d_2, &Q);
	// printf("%d %d %d %d\n", x,d_1,d_2, Q);

	a[1] = x;
	// printf("%ld\n", k[1]);
	for (int i = 2; i <= 1000; i++)
	{
		if (i % 2 == 0)
			a[i] = a[i - 1] + d_2;
		else
			a[i] = a[i - 1] + d_1;
		// printf("%ld\n", a[i]);
	}

	for (int i = 0; i < Q; i++)
	{
		scanf("%ld", &k[i]);
		printf("%ld\n", a[k[i]]);
	}
	
	

	return (0);
}