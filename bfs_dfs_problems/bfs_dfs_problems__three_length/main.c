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
		printf("failed new_queue...\n");
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
Queue	*resize_queue(Queue *self, int new_cap) {
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
void	deque(Queue *self) {
	self->front_idx++;
}
int	empty_queue(Queue *self) {
	return 0 >= (self->last_index - self->front_idx);
}
int	queue_size(Queue *self) {
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

int int_compare(const void * n1, const void * n2) {
	// asc
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
}
typedef struct {
	int vertex; // 頂点
	int	*arr;
	int	len;
	int	cap;
}	AdList;
AdList *arr_resize(AdList *self, int cap) {
	int byte = sizeof(int);
	int size = cap * byte;
	int *tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	push_back(AdList *self, int elem) {
	if (self->len >= self->cap)
	{
		if (! arr_resize(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->arr[self->len] = elem;
	self->len++;
}
AdList *adlist_new(int cap) {
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
	int N, X;
	scanf("%d %d", &N, &X);
	// printf("%d %d\n", N, X);

	AdList **ad_list = calloc(N+1, sizeof(AdList *));

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		// printf("%d %d\n", a, b);
		if (ad_list[a] == NULL) {
			ad_list[a] = adlist_new(4);
		}
		if (ad_list[b] == NULL) {
			ad_list[b] = adlist_new(4);
		}
		push_back(ad_list[a], b);
		push_back(ad_list[b], a);
	}

	Queue *que = new_queue(16);
	enqueue(que, X);

	int *visited = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		visited[i] = -1;
	}
	visited[X] = 0;

	int *ans = calloc(N+1, sizeof(int));
	int j = 0;
	while (! empty_queue(que)) {
		int now = front(que);
		// printf("now=%d\n", now);
		// printf("visited[now]=%d\n", visited[now]);
		deque(que);

		if (visited[now] == 3) {
			ans[j] = now;
			j++;
		}

		// printf("ad_list[now]->len=%d\n", ad_list[now]->len);
		for (int i = 0; i < ad_list[now]->len; i++) {
			int next = ad_list[now]->arr[i];
			if (0 <= ad_list[next]->len && visited[next] == -1) {
				visited[next] = visited[now] + 1;
				enqueue(que, next);
				
				// printf("%d\n", next);
			}
		}
	}

	qsort(ans, j, sizeof(int), cmp_asc);

	for (int i = 0; i < j; i++) {
		printf("%d\n", ans[i]);
	}
	

	return (0);
}