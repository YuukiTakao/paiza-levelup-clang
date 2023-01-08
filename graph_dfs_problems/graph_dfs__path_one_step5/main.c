#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int	*arr;
	int	len;
	int	cap;
}	Vector;
Vector	*resize_vector(Vector *self, int cap) {
	int byte = sizeof(int);
	int size = cap * byte;
	int *tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	push_vector(Vector *self, int elem) {
	if (self->len >= self->cap) {
		if (! resize_vector(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->arr[self->len] = elem;
	self->len++;
}
void	pop_vector(Vector *self) {
	if (1 <= self->len) {
		self->len--;
	}
}
Vector	*new_vector(int cap) {
	Vector *self = calloc(1, sizeof(*self));
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

int in_array(Vector *vector, int n) {
	int exists = 0;
	for (int i = 0; i < vector->len; i++) {
		// printf("len=%d n=%d vector->arr[%d]=%d\n", vector->len, n, i, vector->arr[i]);
		if (vector->arr[i] == n) {
			exists = 1;
			break;
		}
	}
	return exists;
}

int N, S, T, P;
AdList **adlist;
// int *visited;
Vector *min_path;
Vector	*dfs(int position, Vector *path) {
	// printf("path->len=%d min_path->len=%d\n", path->len, min_path->len);
	if (path->len < min_path->len) {
		// visited[position] = 1;
		for (int i = 0; i < adlist[position]->len; i++) {
			int next = adlist[position]->arr[i];
			if (in_array(path, next) == 0) {
				push_vector(path, next);
				// printf("next=%d T=%d P=%d in_array(path, P)=%d\n", next, T, P, in_array(path, P));
				if (next == T && in_array(path, P) == 1) {
					min_path = new_vector(2);
					for (int j = 0; j < path->len; j++) {
						push_vector(min_path, path->arr[j]);
					}
				} else {
					dfs(next, path);
				}
				pop_vector(path);
			}
		}
	}
	return min_path;
}

int	main(void) {
	scanf("%d %d %d %d", &N, &S, &T, &P);
	// printf("%d %d %d %d\n", N, S, T, P);

	adlist = calloc(N+1, sizeof(AdList));
	int v, a;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v);
		if (adlist[i] == NULL) {
			adlist[i] = new_adlist(2);
		}
		for (int j = 1; j <= v; j++) {
			scanf("%d", &a);
			push_adlist(adlist[i], a);
		}
	}
	// debug
	// for (int i = 1; i <= N; i++) {
	// 	printf("%d:", i);
	// 	if (adlist[i] != NULL) {
	// 		for (int j = 0; j < adlist[i]->len; j++) {
	// 			printf(" %d", adlist[i]->arr[j]);
	// 		}
	// 	}
	// 	printf("\n");
	// }
	// visited = calloc(N+1, sizeof(int));
	min_path = new_vector(2);
	for (int i = 1; i <= N + 1; i++) {
		push_vector(min_path, i);
	}

	Vector *path = new_vector(2);
	push_vector(path, S);
	min_path = dfs(S, path);

	if (min_path->len == N+1)
		printf("-1\n");
	else {
		// printf("min_path->len=%d\n", min_path->len);
		for (int i = 0; i < min_path->len; i++){
			if (i >= 1)
				printf(" ");
			printf("%d", min_path->arr[i]);
		}
		printf("\n");
	}
		


	return (0);
}