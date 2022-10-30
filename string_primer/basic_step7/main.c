#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 10000
#define N_SIZE 100

int	main(void)
{
	int		N;
	char	S[STR_SIZE * N_SIZE];

	scanf("%d", &N);
	// printf("%d\n", N);

	for (int i = 0; i < N; i++)
	{
		char	S_i[STR_SIZE];
		scanf("%s", S_i);
		// printf("%s\n", S_i);
		strcat(S, S_i);
	}
	printf("%s", S);

	return (0);
}
