#include <stdio.h>

#define SIZE 5009

int	main(void)
{
	int	n;
	int	a[SIZE];
	int	dp[SIZE];

	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i]);

	int max = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				// printf("i=%d dp[i]=%d j=%d dp[j]+1=%d\n", i,dp[i],j, dp[j] + 1);
				if (dp[i] < dp[j]+ 1)
					dp[i] = dp[j]+ 1;
			}
		}
		if (max < dp[i])
			max = dp[i];
	}
	
	printf("%d\n", max);
	return (0);
}