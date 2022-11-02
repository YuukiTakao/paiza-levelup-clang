#include <stdio.h>

int	main(void)
{
	char	S[10000 + 1];       
	char	c[1 + 1];
	
	scanf("%s", S);
	scanf("%s", c);

	for (int i = 0; S[i] != '\0'; i++)
	{
		if (S[i] == c[0])
		{
			printf("%d", i + 1);
			// break;
		}
	}

	// int	i;
	// i = 0;
	// while (S[i] != '\0')
	// {
	// 	if (S[i] == c[0])
	// 	{
	// 		printf("%d\n", i + 1);
	// 		// break ;
	// 	}
	// 	i++;
	// }
	return (0);
}