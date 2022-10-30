#include <stdio.h>

#define STR_SIZE 10000
#define N_SIZE 5

int	yt_len(char *str)
{
	int	i;
	
	i = 1;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	yt_atoi(char *str)
{
	unsigned int	i;
	unsigned int	len;
	int				n;
	int				digit;
	
	i = 0;
	len = yt_len(str);
	n = 0;
	digit = 1;
	// printf("in atoi len=%d\n", len);
	while (i < len)
	{
		// printf("str[i]=%d\n", str[i]);
		n += (str[len - i - 1] - '0') * digit;
		digit *= 10;
		i++;
	}
	// printf("n=%d\n", n);
	return (n);
}

int	main(void)
{
	char	ANS[STR_SIZE * 2];
	char	S[STR_SIZE];
	char	T[STR_SIZE];
	char	N[N_SIZE];
	int		i = 0;

	scanf("%s", S);
	scanf("%s", T);
	scanf("%s", N);

	// printf("S=%s T=%s N=%s\n", S, T, N);
	// printf("yt_atoi(N)=%d\n", yt_atoi(N));

	int	len = yt_atoi(N);
	// printf("main len=%i\n", len);
	while (i < len)
	{
		// printf("i=%d\n", i );
		ANS[i] = S[i];
		i++;
	}
	
	int	j;
	
	j = 0;
	while (T[j] != '\0')
	{
		// printf("T[j]=%c i=%d j=%d\n", T[j], i, j);
		ANS[i] = T[j];
		i++;
		j++;
	}

	len = yt_atoi(N);
	while (S[len] != '\0')
	{
		ANS[i] = S[len];
		len++;
		i++;
	}
	ANS[i] = '\0';
	printf("%s", ANS);
	return (0);
}
