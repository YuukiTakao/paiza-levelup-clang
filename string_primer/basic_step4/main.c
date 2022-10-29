#include <stdio.h>

int	main(void)
{
	char	str[100];
	char	*p = "paiza\n";
	int		i;
	int		is_same;

	fgets(str, 100, stdin);

	i = 0;
	is_same = 1;
	while (str[i] != '\0')
	{
// 		printf("str[i]=%c p[i]=%c\n", str[i], p[i]);
		if (str[i] != p[i])
		{
			is_same = 0;
			break ;
		}
		i++;
	}
	if (is_same == 1)
		printf("YES");
	else 
		printf("NO");
	return (0);
}