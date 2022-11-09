#include <stdio.h>

int	main(void)
{
	int	n;
	int	a;
	int	b;
	int	dp[1009];

	scanf("%d%d%d", &n,&a,&b);
	// printf("%d %d %d\n", n, a,b);
	dp[0] = 0;
	dp[1] = a;

	for (int i = 2; i <= n; i++)
	{
		if (dp[i - 1] + a < dp[i - 2] + b)
			dp[i] = dp[i - 1] + a;
		else
			dp[i] = dp[i - 2] + b;
	}
	printf("%d", dp[n]);	
	return (0);
}