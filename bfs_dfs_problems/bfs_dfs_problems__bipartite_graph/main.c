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
int	bi_partite_dfs(int now, int color) {
	visited[now] = color;
	for (int i = 0; i < adlist[now]->len; i++) {
		int next = adlist[now]->arr[i];
		if (visited[next] != -1) {
			if (visited[next] == color) {
				return 0;
			}
			continue;
		}
		if (bi_partite_dfs(next, 1 - color) == 0) {
			return 0;
		}
	}
	return 1;
}

int	main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	// printf("%d %d\n", N, M);

	adlist = calloc(N+1, sizeof(AdList *));
	int a, b;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		if(adlist[a] == NULL) {
			adlist[a] = new_adlist(2);
		}
		if(adlist[b] == NULL) {
			adlist[b] = new_adlist(2);
		}
		push_adlist(adlist[a], b);
		push_adlist(adlist[b], a);
	}

	visited = calloc(N+1 ,sizeof(int));
	for (int i = 1; i <= N; i++) {
		visited[i] = -1;
	}

	int is_bipartite = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != -1) {
			continue;
		}
		if (adlist[i] != NULL && bi_partite_dfs(i, 0) == 0) {
			is_bipartite = 0;
		}
	}
	
	if (is_bipartite == 1)
		printf("Yes\n");
	else
		printf("No\n");

	return (0);
}