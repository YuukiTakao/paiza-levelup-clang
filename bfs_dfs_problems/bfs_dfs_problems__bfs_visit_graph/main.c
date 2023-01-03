#include <stdio.h>
#include <stdlib.h>

int	cmp_asc(const void *n1, const void *n2) {
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
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
typedef struct {
	int	vertex; // 頂点
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

int	main(void) {
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);
	// printf("%d %d %d\n", N, M, X);

	AdList **adlist = calloc(N+1, sizeof(adlist));
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		if (adlist[a] == NULL) {
			adlist[a] = new_adlist(2);
		}
		if (adlist[b] == NULL) {
			adlist[b] = new_adlist(2);
		}
		push_adlist(adlist[a], b);
		push_adlist(adlist[b], a);
	}

	int *visited = calloc(N+1 ,sizeof(int));
	for (int i = 1; i <= N; i++) {
		visited[i] = -1;
	}
	visited[X] = 0; 
	
	Queue *que = new_queue(4);
	enqueue(que, X);

	if (adlist[X] == NULL) {
		printf("%d\n", X);
		return 0;
	}

	qsort(adlist[X]->arr, adlist[X]->len, sizeof(int), cmp_asc);

	while(! empty_queue(que)) {
		int now = front(que);
		deque(que);
		printf("%d\n", now);
		for (int i = 0; i < adlist[now]->len; i++) {
			int next = adlist[now]->arr[i];
			if (adlist[next]->len >= 2) {
				qsort(adlist[next]->arr, adlist[next]->len, sizeof(int), cmp_asc);
			}
			if (visited[next] == -1) {
				visited[next] = visited[now] + 1;
				enqueue(que, next);
			}
		}
	}

	return (0);
}