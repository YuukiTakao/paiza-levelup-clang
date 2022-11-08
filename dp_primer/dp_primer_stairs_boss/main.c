#include <stdio.h>

int	main(void)
{
	int	n, a,b,c;
	int	dp[31] = {0};

	scanf("%d%d%d%d", &n,&a,&b,&c);
	// printf("%d%d%d%d",n,a,b,c);

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i >= a)
			dp[i] += dp[i - a];
		if (i >= b)
			dp[i] += dp[i - b];
		if (i >= c)
			dp[i] += dp[i - c];
	}

	printf("%d\n", dp[n]);
	
	return (0);
}