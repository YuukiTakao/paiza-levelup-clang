#include <stdio.h>

char	*yt_strstr(char *str, int i, int j)
{
	str[j] = '\0';
	str += (i - 1);
	return (str);
}

int	main(void)
{
	char	S[10000];
	// char	*p_S;
	int		i;
	int		j;

	// p_S = S;

	scanf("%s", S);
	scanf("%d", &i);
	scanf("%d", &j);

	// printf("%s\n", S);
	// printf("%d\n", i);
	// printf("%d\n", j);

	// p_S[j] = '\0';
	// p_S += (i - 1);
	
	printf("%s\n", yt_strstr(S, i, j));
	// printf("%s", p_S);
	return (0);
}

