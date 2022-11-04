#include <stdio.h>

int	main(void)
{
	int			k;
	long int	a[40];

	scanf("%d", &k);
	// printf("%d\n", k);
	// ・ a_1 = 1 
	// ・ a_2 = 1 
	// ・ a_n = a_{n-2} + a_{n-1} (n ≧ 3)
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= 40; i++)
	{
		a[i] = a[i - 2] + a[i -1];
	}
	printf("%ld", a[k]);
	
	return (0);
}