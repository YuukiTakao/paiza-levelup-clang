#include <stdio.h>
#include <stdlib.h>

int	min_int(const int a, const int b) {
	if (a <= b)
		return (a);
	else
		return (b);
}
int	max_int(const int a, const int b) {
	if (a <= b)
		return (b);
	else
		return (a);
}

int	main(void) {
	int H, W;
	scanf("%d %d", &H, &W);
	// printf("%d %d\n", H, W);

	int y, x;
	scanf("%d %d", &y, &x);
	// printf("%d %d\n", y, x);

	char **map = calloc(H+5, sizeof(char *));
	for (int i = 0; i < H; i++) {
		map[i] = calloc(W+5, sizeof(char));
		
		int j;
		for (j = 0; j < W; j++) {
			map[i][j] = '.';
		}
		map[i][j] = '\0';
	}
	
	int ymax = max_int(y - 1, 0);
	map[ymax][x] = '*';

	int ymin = min_int(y + 1, H - 1);
	map[ymin][x] = '*';

	int xmin = min_int(x + 1, W - 1);
	map[y][xmin] = '*';

	int xmax = max_int(0, x - 1);
	map[y][xmax] = '*';

	map[y][x] = '*';

	for (int i = 0; i < H; i++) {
		// for (int j = 0; j < W; j++) {
			
		// }
		printf("%s\n", map[i]);
	}
	return (0);
}