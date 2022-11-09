#include <stdio.h>

int	main(void)
{
	int n;
	int	x;
	int	a;
	int	y;
	int	b;
	int dp[3009];

	scanf("%d%d%d%d%d", &n,&x,&a,&y,&b);

	// printf("%d %d %d %d %d", n,x,a,y,b);

	dp[0] = 0;
	for (int i = 1; i < n + y + x; i++)
	{
		dp[i] = 1800900900;
		if (i >= x)
		{
			if (dp[i - x] + a < dp[i])
				dp[i] = dp[i - x] + a;
		}
		if (i >= y)
		{
			if (dp[i - y] + b < dp[i])
				dp[i] = dp[i - y] + b;
		}
	}

	for (int i = n + (y + x - 2); i >= 1; i--)
	{
		if (dp[i] > dp[i + 1])
			dp[i] = dp[i + 1];
		else
			dp[i] = dp[i];
		// printf("i=%d => %d\n",i, dp[i]);
	}
	printf("%d",dp[n]);
	
	
	return (0);
}