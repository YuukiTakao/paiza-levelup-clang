#include <stdio.h>
#include <stdlib.h>

int **map;
int **visited;

void	grid_dfs(int H, int W, int y, int x) {
	visited[y][x] = 1;
	for (int i = -1; i <= 1; i += 2) {
		if (0 <= y+i && y+i < H && visited[y+i][x] == 0 && map[y+i][x] == 1) {
			grid_dfs(H, W, y+i, x);
		}
		if (0 <= x+i && x+i < W && visited[y][x+i] == 0 && map[y][x+i] == 1) {
			grid_dfs(H, W, y, x+i);
		}
	}
}

int	main(void) {
	int M, N;
	scanf("%d %d", &M, &N);
	// printf("%d %d\n", M, N);

	map = calloc(N+1, sizeof(int *));
	for (int i = 0; i < N; i++) {
		map[i] = calloc(M+1, sizeof(int));
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			// if (j >= 1)
			// 	printf(" ");
			// printf("%d", map[i][j]);
		}
		// printf("\n");
	}

	visited = calloc(N+1, sizeof(int *));
	for (int i = 0; i <= N; i++) {
		visited[i] = calloc(M+1, sizeof(int));
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 1 || map[i][j] == 0)
				continue;
			grid_dfs(N, M, i, j);
			count++;
		}
	}
	
	printf("%d\n", count);

	return (0);
}