#include <stdio.h>

int	main(void)
{
	int x, d, Q;
	int k[1001];
	int a[1001];

	scanf("%d %d %d", &x,&d,&Q);

	a[1] = x;
	// printf("%d %d %d %d\n", x,d,Q, a[0]);

	for (int i = 2; i <= 1000; i++)
		a[i] = a[i - 1] + d;

	scanf("%d", &k[0]);
	for (int n = 1; n <= Q; n++)
	{
		scanf("%d", &k[n]);
		printf("%d\n", a[k[n - 1]]);
	}
	
	return (0);
}