#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);

	int *queue;
	queue = calloc(Q+1, sizeof(int));
	int j = 0;
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);

		if (q == 1) {
			int x;
			scanf("%d", &x);

			queue[j] = x;
			j++;
		}
	}
	printf("%d\n", j);
	for (int i = 0; i < j; i++) {
		printf("%d\n", queue[i]);
	}
	
	return (0);
}