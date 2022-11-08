#include <stdio.h>

// 整数 n, a, b が与えられます。
// 階段を上るのに、1歩で a 段または b 段を
// 上ることができるとき、n 段の階段を上る方法は
// 何通りあるでしょうか。
int	main(void)
{
	int	n; // n 段の階段
	int	a; // １歩で登れる段数
	int	b; // １歩で登れる段数
	int dp[41] = {0};

	scanf("%d %d %d", &n , &a, &b);

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i >= a)
			dp[i] += dp[i - a];
		if (i >= b)
			dp[i] += dp[i - b];
	}
	printf("%d\n", dp[n]);
	
	return (0);
}