#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
	int first;
	int second;
}	Pair;

typedef Pair QUEUE_TYPE;
typedef struct Queue {
	QUEUE_TYPE	*array;
	int			last_index;
	int			cap;
	int			front_idx;
}	Queue;
Queue	*new(int cap) {
	Queue *self = calloc(1, sizeof(Queue));
	if (!self)
		printf("failed Queue new...\n");
	self->cap = cap;
	self->last_index = 0;
	self->front_idx = 0; 
	self->array = calloc(self->cap, sizeof(QUEUE_TYPE));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
Queue	*resize(Queue *self, int new_cap) {
	int new_size = new_cap * sizeof(QUEUE_TYPE);
	QUEUE_TYPE *tmp = realloc(self->array, new_size);
		if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
void	pop(Queue *self) {
	self->front_idx++;
}
int	empty(Queue *self) {
	return 0 >= (self->last_index - self->front_idx);
}
int	queue_size(Queue *self) {
	return self->last_index - self->front_idx;
}
QUEUE_TYPE	front(Queue *self) {
	return self->array[self->front_idx];
}
void	push_back(Queue *self, QUEUE_TYPE elem) {
	if (self->last_index >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	// self->array[self->last_index] = calloc(strlen(elem), sizeof(char));
	self->array[self->last_index] = elem;
	self->last_index++;
}

int	main(void) {
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);
	// printf("H=%d W=%d N=%d\n", H, W, N);

	int y, x;
	scanf("%d %d", &y, &x);

	char **map = calloc(H+1, sizeof(char *));
	int **visited = calloc(H+1, sizeof(int *));
	for (int i = 0; i < H; i++) {
		map[i] = calloc(W+1, sizeof(char));
		visited[i] = calloc(W+1, sizeof(int));
		scanf("%s", map[i]);
		for (int j = 0; j < W; j++) {
			visited[i][j] = -1;
		}
	}

	map[y][x] = '*';
	visited[y][x] = 0;

	Queue *que = new(4);
	Pair start;
	start.first = y;
	start.second = x;

	push_back(que, start);

	while(! empty(que)) {
		Pair now = front(que);
		int ny = now.first;
		int nx = now.second;
		// printf("ny=%d nx=%d\n", ny, nx);
		pop(que);

		if (visited[ny][nx] == N)
			break;

		for (int i = -1; i <= 1; i += 2) {
			if (0 <= ny + i && ny + i < H && map[ny+i][nx] == '.' && visited[ny+i][nx] == -1) {
				map[ny + i][nx] = '*';
				visited[ny+i][nx] = visited[ny][nx] + 1;
				Pair next;
				next.first = ny+i;
				next.second = nx;
				push_back(que, next);
			}
			if (0 <= nx + i && nx + i < W && map[ny][nx+i] == '.' && visited[ny][nx+i] == -1) {
				map[ny][nx+i] = '*';
				visited[ny][nx+i] = visited[ny][nx] + 1;
				Pair next;
				next.first = ny;
				next.second = nx+i;
				push_back(que, next);
			}
		}
		
	}

	// for debug
	// for (int i = 0; i < H; i++) {
	// 	for (int j = 0; j < W; j++) {
	// 		if (j >= 1)
	// 			printf(" ");
	// 		printf("%d", visited[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (int i = 0; i < H; i++) {
		printf("%s\n", map[i]);
	}
	return (0);
}