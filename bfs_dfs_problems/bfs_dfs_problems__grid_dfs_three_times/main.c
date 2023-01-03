#include <stdio.h>
#include <stdlib.h>

void dfs(int times, int y, int x, int H, int W) {
	// printf("times=%d y=%d x=%d\n", times, x, y);
	if (times == 3) {
		printf("%d %d\n", y, x);
	} else {
		if (0 <= y - 1)
			dfs(times+1, y-1, x, H, W);
		if (x+1 < W) 
			dfs(times+1, y, x+1, H, W);
		if (y+1 < H)
			dfs(times+1, y+1, x, H, W);
		if (0 <= x-1)
			dfs(times+1, y, x-1, H, W);
	}
	// printf("end times=%d\n", times);
}
int	main(void) {
	int H, W;
	int y, x;
	scanf("%d %d %d %d", &H, &W, &y, &x);
	// printf("%d %d %d %d\n", H, W, y, x);
	dfs(0, y, x, H, W);

	return (0);
}