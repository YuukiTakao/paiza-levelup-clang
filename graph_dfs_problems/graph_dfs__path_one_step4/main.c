#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int	vertex;
	int	*arr;
	int	len;
	int	cap;
}	AdList;
AdList	*resize_adlist(AdList *self, int cap) {
	int byte = sizeof(int);
	int size = cap * byte;
	int *tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	push_adlist(AdList *self, int elem) {
	if (self->len >= self->cap)
	{
		if (! resize_adlist(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->arr[self->len] = elem;
	self->len++;
}
AdList	*new_adlist(int cap) {
	AdList *self = calloc(1, sizeof(*self));
	if (!self)
		return NULL;
	self->cap = cap;
	self->arr = calloc(self->cap, sizeof(int));
	if (!self->arr) {
		free(self);
		return NULL;
	}
	return self;
}

typedef int QUEUE_TYPE;
typedef struct Queue {
	QUEUE_TYPE	*array;
	int			last_index;
	int			cap;
	int			front_idx;
}	Queue;
Queue	*new_queue(int cap) {
	Queue *self = calloc(1, sizeof(Queue));
	if (!self)
		printf("failed Queue new...\n");
	self->cap = cap;
	self->last_index = 0;
	self->front_idx = 0; 
	self->array = calloc(self->cap, sizeof(QUEUE_TYPE));
	if (self->array == NULL) {
		printf("failed new_queue memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
Queue	*resize_queue(Queue *self, int new_cap) {
	int new_size = new_cap * sizeof(QUEUE_TYPE);
	QUEUE_TYPE *tmp = realloc(self->array, new_size);
		if (tmp == NULL) {
		printf("failed resize_queue realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
void	deque(Queue *self) {
	self->front_idx++;
}
int	empty_queue(Queue *self) {
	return 0 >= (self->last_index - self->front_idx);
}
int	size_queue(Queue *self) {
	return self->last_index - self->front_idx;
}
QUEUE_TYPE	front(Queue *self) {
	return self->array[self->front_idx];
}
void	enqueue(Queue *self, QUEUE_TYPE elem) {
	if (self->last_index >= self->cap) {
		if (resize_queue(self, self->cap * 2) == NULL) {
			printf("failed enqueue in realloc...\n");
		}
	}
	// self->array[self->last_index] = calloc(strlen(elem), sizeof(char));
	self->array[self->last_index] = elem;
	self->last_index++;
}

typedef struct PathInfo {
	int *path;
	int distance;
}	PathInfo;
PathInfo	*graph_bfs_shortest_path(AdList **adlist, int N, int S, int T) {
	int *visited = calloc(N+1, sizeof(int));
	int *prev = calloc(N+1, sizeof(int));
	for (int i = 0; i <= N; i++) {
		prev[i] = -1;
		visited[i] = -1;
	}
	visited[S] = 0;
	Queue *que = new_queue(2);
	enqueue(que, S);
	while (! empty_queue(que)) {
		int now = front(que);
		deque(que);
		// printf("now=%d\n", now);
		if (now == T)
			break;
		for (int i = 0; i < adlist[now]->len; i++) {
			int next = adlist[now]->arr[i];
			if (visited[next] == -1) {
				visited[next] = visited[now] + 1;
				prev[next] = now;
				enqueue(que, next);
			}
		}
	}
	int *path = calloc(N+1, sizeof(int));
	int j = 0;
	int tmp = T;
	while (tmp != -1) {
		path[j++] = tmp;
		tmp = prev[tmp];
	}
	PathInfo *pi = calloc(1, sizeof(PathInfo));
	pi->path = path;
	pi->distance = j;
	return pi;
}

int	main(void) {
	int N, S, T;
	scanf("%d %d %d", &N, &S, &T);
	// printf("%d %d %d\n", N, S, T);

	AdList **adlist = calloc(N+1, sizeof(AdList));
	int v, a;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &v);

		if (adlist[i] == NULL) {
			adlist[i] = new_adlist(2);
		}
		for (int j = 0; j < v; j++) {
			scanf("%d", &a);
			push_adlist(adlist[i], a);
		}
	}

	// debug
	// for (int i = 0; i < N; i++) {
	// 	if (adlist[i] == NULL)
	// 		continue;
	// 	printf("%d:", i);
	// 	for (int j = 0; j < adlist[i]->len; j++) {
	// 		printf(" %d", adlist[i]->arr[j]);
	// 	}
	// 	printf("\n");
	// }

	PathInfo *pi = graph_bfs_shortest_path(adlist, N, S, T);

	int *ans = pi->path;
	int j = pi->distance;

	for (int i = j - 1; i >= 0; i--) {
		if (j - 2 >= i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	
	return (0);
}