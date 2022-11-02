#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	yt_pow(int num, int pow)
{
	int	i;
	int	ans;
	// printf("before num=%d pow=%d\n", num, pow);
	i = 0;
	ans = 1;
	while (i < pow)
	{
		// printf("i=%d num=%d ans=%d\n", i, num, ans);
		ans *= num;
		i++;
	}
	// printf("ans=%d", ans);
	return (ans);
}

int	yt_len(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	yt_atoi(char *str)
{
	int	i;
	int digit;
	int res;


	if (str[0] == '\0')
		return (0);

	int len = yt_len(str);
	// printf("len=%d\n", len);
	digit = yt_pow(10, len - 1);

	// printf("digit=%d\n", digit);
	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			res += (str[i] - '0') * digit;
			digit /= 10;
		}
		i++;
	}
	return (res);
}

int	main(void)
{
	char	S[9];

	scanf("%s", S);
	printf("%d", yt_atoi(S) - 813);
	return (0);
}