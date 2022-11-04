#include <stdio.h>

int	main(void)
{
	int x, d_1, d_2, k;
	long int a[1000];
	/* 
	・ a_1 = x 
	・ a_n = a_{n-1} + d_1 (n が奇数のとき、n ≧ 3) 
	・ a_n = a_{n-1} + d_2 (n が偶数のとき)
	*/
	scanf("%d %d %d %d", &x, &d_1, &d_2, &k);
	// printf("%d %d %d %d\n", x, d_1,d_2,k);

	a[1] = x;

	for (int i = 2; i <= k; i++)
	{
		if (i % 2 == 0)
			a[i] = a[i - 1] + d_2;
		else
		{
			a[i] = a[i - 1] + d_1;
		}
	}
	printf("%ld\n", a[k]);
	
	return (0);
}