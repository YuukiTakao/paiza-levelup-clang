#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int n, s, k;
	scanf("%d %d %d", &n, &s, &k);
	// printf("%d %d %d\n", n, s, k);

	int is_up = 0;
	int i = 0;
	int j = 0;
	while (j < k + 1) {
		if (s - i == 1) {
			is_up = 1;
		}
		int ans = s - i;
		if (j >= 1)
			printf(" ");
		printf("%d", ans);
		
		if (is_up == 1)
			i--;
		else
			i++;
		j++;
	}
	printf("\n");
	
	
	return (0);
}