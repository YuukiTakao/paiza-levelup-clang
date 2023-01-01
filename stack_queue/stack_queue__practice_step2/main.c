#include <stdio.h>
#include <stdlib.h>


int	main(void) {
	int N, X;
	scanf("%d %d", &N, &X);
	// printf("%d %d\n", N, X);

	int *A = calloc(N+1, sizeof(int));
	int *psum = calloc(N+1, sizeof(int));
	psum[0] = 0;
	// printf("psum[%d]=%d\n", 0, psum[0]);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		psum[i] = psum[i - 1] + A[i];
		// printf("psum[%d]=%d\n", i, psum[i]);
	}

	int	i = 1;
	int last = X;

	int max = -1;
	int max_i = -1;
	while (last <= N) {
		// printf("psum[i]=%d psum[last]=%d\n", psum[i], psum[last]);
		int sum = psum[last] - psum[i - 1];
		
		// printf("i=%d sum=%d\n", i, sum);
		if (max < sum) {
			max = sum;
			max_i = i;
		}
		last++;
		i++;
	}
	printf("%d %d\n", max, A[max_i]);
	
	return (0);
}
