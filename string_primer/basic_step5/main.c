#include <stdio.h>

#define SIZE 10000

int	main(void)
{
	char	str[SIZE];
	int		i;

	fgets(str, SIZE, stdin);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	printf("%d\n", i);
	return (0);
}