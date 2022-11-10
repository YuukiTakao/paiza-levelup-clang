#include <stdio.h>

#define SIZE 200009;

int	main(void)
{
	int	n;
	int	a[200009];
	int	dp[200009];
	int	max;

	scanf("%d", &n);

	a[0] = 0;
	dp[0] = 0;
	max = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);

		if (a[i - 1] >= a[i] || a[i - 1] == 0)
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;
		if (max < dp[i])
			max = dp[i];
	}
	printf("%d", max);
	
	return (0);
}