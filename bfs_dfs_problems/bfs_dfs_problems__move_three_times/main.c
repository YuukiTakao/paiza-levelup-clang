#include <stdio.h>
#include <stdlib.h>

int	max_int(const int a, const int b) {
	if (a <= b)
		return (b);
	else
		return (a);
}

int	min_int(const int a, const int b) {
	if (a <= b)
		return (a);
	else
		return (b);
}

typedef char TDARRAY_TYPE;
TDARRAY_TYPE **init_tdarray(int H, int W, TDARRAY_TYPE init) {
	TDARRAY_TYPE **map;
	map = calloc(H+1, sizeof(TDARRAY_TYPE *));
	for (int i = 0; i < H; i++) {
		map[i] = calloc(W+1, sizeof(TDARRAY_TYPE));
		int j;
		for (j = 0; j < W; j++) {
			map[i][j] =  init;
		}
		map[i][j] = '\0';
	}
	return map;
}

int	main(void) {
	int H, W;
	scanf("%d %d", &H, &W);
	// printf("%d %d\n", H, W);

	TDARRAY_TYPE **map = init_tdarray(H, W, '.');

	int y, x;
	scanf("%d %d", &y, &x);
	// printf("%d %d\n", y, x);

	map[y][x] = '*';

	int **visited = calloc(H+1, sizeof(int *));
	for (int i = 0; i < H; i++)  {
		visited[i] = calloc(W+1, sizeof(int));
		for (int j = 0; j < W; j++) {
			visited[i][j] = -1;
		}
		
	}
	visited[y][x] = 0;

	
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (k == visited[i][j]) {
					int ytop = i - 1;
					if (0 <= ytop) {
						map[ytop][j] = '*';
						visited[ytop][j] = visited[i][j] + 1;
					}
					int ybot = i + 1;
					if (ybot <= H - 1) {
						map[ybot][j] = '*';
						visited[ybot][j] = visited[i][j] + 1;
					}
					int xleft = j - 1;
					if (0 <= xleft) {
						map[i][xleft] = '*';
						visited[i][xleft] = visited[i][j]+ 1;
					}
					int xright = j + 1;
					if (xright <= W - 1) {
						map[i][xright] = '*';
						visited[i][xright] = visited[i][j] + 1;
					}
				}
			}
		}
		
	}

	for (int i = 0; i < H; i++) {
		printf("%s\n", map[i]);
	}

	return (0);
}