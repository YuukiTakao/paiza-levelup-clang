#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 10000

int	main(void)
{
	char	str[STR_SIZE];
	char	c[2];
	int		i;

	fgets(str, STR_SIZE, stdin);
	fgets(c, 2, stdin);
    // printf("str=%s c=%s\n", str, c);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == c[0])
			break ;
		i++;
	}
	printf("%d", i + 1);
	return (0);
}