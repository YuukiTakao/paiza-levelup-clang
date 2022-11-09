#include <stdio.h>

int	main(void)
{
	int	n;
	int	a;
	int	b;
	int	dp[1009];

	scanf("%d%d%d", &n, &a, &b);
	// printf("%d %d %d\n", dp[0], dp[1], dp[2]);

	dp[0] = 0;
	// dp[2] = b; dp[i - 2] + a < 
	// dp[3] = b;
	// dp[4] = b;
	// dp[5] = b; 200 
	// dp[6] = b + a; 310 ↑
	// dp[7] = b + a; 310
	// dp[8] = b + a + a; 420↑
	// dp[9] = b + b + a; 420 
	// dp[10] = b + b;
	// dp[11] = b + b + a; 510 ↑
	for (int i = 1; i < n + 5; i++)
	{
		dp[i] = 10908076;
		if (i >= 2)
		{
			if (dp[i - 2] + a < dp[i])
				dp[i] = dp[i - 2] + a;
			else 
				dp[i] = dp[i];
		}
		if (i >= 5)
		{
			if (dp[i - 5] + b < dp[i])
				dp[i] = dp[i - 5] + b;
			else 
				dp[i] = dp[i];
		}
	}

	for (int i = n + 3; i >= 1; i--)
	{
		if (dp[i] > dp[i + 1])
			dp[i] = dp[i + 1];
		else
			dp[i] = dp[i];
	}
	
	printf("%d", dp[n]);
	
	return (0);
}