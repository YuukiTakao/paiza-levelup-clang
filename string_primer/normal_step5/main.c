#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	long int	X;
	long int	Y;
	int			N;

	scanf("%ld %ld %d", &X, &Y, &N);
	// printf("%ld %ld %d\n", X, Y, N);
	X = X + Y;
	// printf("%ld\n", X);

	char	ans[20];
	sprintf(ans, "%ld",X);
	printf("%c", ans[N - 1]);
	return (0);
}