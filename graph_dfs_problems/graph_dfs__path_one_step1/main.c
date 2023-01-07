#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int n, s;
	scanf("%d %d", &n, &s);

	int max = 0;
	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);

		int *a = calloc(v+1, sizeof(int));
	
		for (int j = 1; j <= v; j++) {
			scanf("%d", &a[j]);

			if (i == s) {
				if (max < a[j]) {
					max = a[j];
				}
			}
		}
	}

	printf("%d\n", max);
}