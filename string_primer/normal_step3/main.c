#include <stdio.h>

int	main(void)
{
	char	S[100];       
	int		i;
	char 	c[1 + 1];

	scanf("%s", S);
	scanf("%d", &i);
	scanf("%s", c);
	S[i-1] = c[0];
	printf("%s", S);
	return (0);
}