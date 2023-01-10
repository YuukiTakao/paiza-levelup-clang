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

int	main(void) {
	int N, S, K;
	scanf("%d %d %d", &N, &S, &K);
	// printf("%d %d %d\n", N, S, K);

	AdList **adlist = calloc(N+1, sizeof(AdList));

	for (int i = 1; i <= N; i++) {
		if (adlist[i] == NULL) {
			adlist[i] = new_adlist(2);
		}
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			if (adlist[j] == NULL) {
				adlist[j] = new_adlist(2);
			}
			// printf("i=%d j=%d\n", i, j);
			push_adlist(adlist[i], j);
			// push_adlist(adlist[j], i);
		}
	}
	int *visited = calloc(N+1, sizeof(int));

	printf("%d", S);
	visited[S] = 1;

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adlist[i]->len; j++) {
			if (i == j)
				continue;
			if (visited[adlist[i]->arr[j]] == 0) {
				printf(" %d", adlist[i]->arr[j]);
				visited[adlist[i]->arr[j]] = 1;
				count++;
				if (count == K) {
					printf("\n");
					return 0;
				}
			}
		}
	}
	printf("\n");
	

	return (0);
}