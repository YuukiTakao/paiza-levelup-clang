#include <stdio.h>

int	main(void)
{
	int n;
	int	x;
	int	a;
	int	y;
	int	b;
	int	z;
	int	c;
	int dp[5000];

	scanf("%d %d %d %d %d %d %d", &n,&x,&a,&y,&b,&z,&c);
	// printf("%d %d %d %d %d %d %d", n,x,a,y,b,z,c);

	dp[0] = 0;

	for (int i = 1; i < n+x+y+z; i++)
	{
		dp[i] = 1900000000;
		if (i >= x)
		{
			if (dp[i] > dp[i - x] + a)
				dp[i] = dp[i - x] + a;
		}
		if (i >= y)
		{
			if (dp[i] > dp[i - y] + b)
				dp[i] = dp[i - y] + b;
		}
		if (i >= z)
		{
			if (dp[i] > dp[i - z] + c)
				dp[i] = dp[i - z] + c;
		}
	}

	for (int i = n+x+y+z-2; i >= 1; i--)
	{
		if (dp[i] > dp[i+1])
			dp[i] = dp[i+1];
	}
	printf("%d", dp[n]);
	
	
	return (0);
}