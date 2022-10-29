#include <stdio.h>
// #include <stdlib.h>

int	main(void)
{
	char	str[1000];
	// char	ci[3];
	int		i;

	fgets(str, sizeof(str), stdin);
	scanf("%d", &i);
	printf("%c\n", str[i - 1]);
	return (0);
}