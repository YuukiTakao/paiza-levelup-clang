#include <stdio.h>
#include <stdlib.h>

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

AdList **adlist;
int *visited;
void dfs(int position) {
	if (adlist[position] != NULL) {
		visited[position] = 1;
		for (int i = 0; i < adlist[position]->len; i++) {
			int next = adlist[position]->arr[i];
			if (visited[next] == -1)
				dfs(next);
		}
	}
	return ;
}

int	main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	// printf("%d %d\n", N, M);

	adlist = calloc(N+1, sizeof(AdList *));
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		// printf("%d %d\n", a, b);
		if (adlist[a] == NULL) {
			adlist[a] = new_adlist(2);
		}
		if (adlist[b] == NULL) {
			adlist[b] = new_adlist(2);
		}
		push_adlist(adlist[a], b);
		push_adlist(adlist[b], a);
	}

	visited = calloc(N+1, sizeof(int));
	for (int i = 1; i <= N; i++) {
		visited[i] = -1;
	}
	
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) 
			continue;
		dfs(i);
		count++;
	}

	// for (int i = 1; i <= N; i++) {
	// 	printf("vi=%d\n", visited[i]);
	// }
	
	printf("%d\n", count);

	
	return (0);
}