#include <stdio.h>

#define SIZE 200009

int	main(void)
{
	int	n;
	int	a[SIZE];
	int	dp[SIZE];
	int	max;

	scanf("%d", &n);
	dp[0] = 0;
	max = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		// dp[i] = 1900800700;
		if (a[i - 1] <= a[i])
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;

		if (max < dp[i])
			max = dp[i];
	}
	printf("%d",max);
	return (0);
}