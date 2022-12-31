#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int N;
	scanf("%d", &N);
	printf("%d\n", N);

	int *A;
	A = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		printf("%d\n", A[i]);
	}
	return (0);
}