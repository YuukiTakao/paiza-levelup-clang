#include <stdio.h>

#define SIZE 5010

int	main(void)
{
	int	n;
	int	a[SIZE];
	int	dp[SIZE];

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	dp[1] = 1;
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			if (a[j] < a[i])
			{
				if (dp[i] < dp[j]+1)
					dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d", ans);
	return (0);
}