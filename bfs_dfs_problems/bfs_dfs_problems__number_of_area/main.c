#include <stdio.h>
#include <stdlib.h>

typedef char TDARRAY_TYPE;
TDARRAY_TYPE **init_tdarray(int H, int W) {
	TDARRAY_TYPE **map;
	map = calloc(H+1, sizeof(TDARRAY_TYPE *));
	for (int i = 0; i < H; i++) {
		map[i] = calloc(W+1, sizeof(TDARRAY_TYPE));
		scanf("%s", map[i]);
	}
	return map;
}

void	grid_dfs(int H, int W, int **visited,int y, int x, char **map) {
	visited[y][x] = 1;
	for (int i = -1; i <= 1; i += 2) {
		if (0 <= y+i && y+i < H && visited[y+i][x] == 0 && map[y+i][x] == '.') {
			grid_dfs(H, W, visited, y+i, x, map);
		}
		if (0 <= x+i && x+i < W && visited[y][x+i] == 0 && map[y][x+i] == '.') {
			grid_dfs(H, W, visited, y, x+i, map);
		}
	}
}

int	main(void) {
	int H, W;
	scanf("%d %d", &H, &W);
	// printf("%d %d\n", H, W);

	char **map = init_tdarray(H, W);
	int **visited = calloc(H+1, sizeof(int *));
	for (int i = 0; i < H; i++) {
		visited[i] = calloc(W+1, sizeof(int));
	}
	
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == '.' && visited[i][j] == 0) {
				grid_dfs(H, W, visited, i, j, map);
				ans += 1;
			}
		}
	}
	printf("%d\n", ans);

	return (0);
}