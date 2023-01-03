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

void dfs(AdList **G, int *visited, int position) {
	visited[position] = 1;
	printf("%d\n", position);
	for (int i = 0; i < G[position]->len; i++) {
		qsort(G[position]->arr, G[position]->len, sizeof(int), cmp_asc);
		int next = G[position]->arr[i];
		if (visited[next] == 0)
			dfs(G, visited, next);
	}
	return ;
}

int	main(void) {
	int N, X;
	scanf("%d %d", &N, &X);
	// printf("%d %d\n", N, X);

	AdList **adlist = calloc(N+1, sizeof(AdList *));
	int a, b;
	for (int i = 0; i < N - 1; i++) {
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
	if (adlist[X] == NULL) {
		printf("%d\n", X);
		return 0;
	}

	qsort(adlist[X]->arr, adlist[X]->len, sizeof(int), cmp_asc);

	int *visited = calloc(N+1, sizeof(int));
	
	dfs(adlist, visited, X);
	
	return (0);
}