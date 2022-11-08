#include <stdio.h>

int	main(void)
{
	int n;
	int	dp[41];
	int	i;

	scanf("%d", &n);
	// printf("%d\n", n);
	// 1 => 1
	// 2 => 11,2
	// 3 => 111,12,21
	// 4 => 1111,112,121,211,22
	// 5 => 11111,1112,1121,1211,2111,122,212,221
	dp[1] = 1;
	dp[2] = 2;
	for (i = 3; i <= 40; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	printf("%d", dp[n]);
	
	return (0);
}