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
void	reset_vector(Vector *vector) {
	vector->len = 0;
}
void	print_vector_with_space(Vector *vector) {
	for (int i = 0; i < vector->len; i++){
		if (i >= 1)
			printf(" ");
		printf("%d", vector->arr[i]);
	}
	printf("\n");
}

Vector	*init_min_path(int v_count) {
	Vector *min_path = new_vector(2);
	for (int i = 1; i <= v_count + 1; i++) {
		push_vector(min_path, i);
	}
	return min_path;
}
Vector	*dfs_with_transit(int position, int goal, int transit, Vector *path, AdList **adlist, Vector *min_path) {
	if (path->len < min_path->len) {
		for (int i = 0; i < adlist[position]->len; i++) {
			int next = adlist[position]->arr[i];
			if (in_array(path, next) == 0) {
				push_vector(path, next);
				if (next == goal && in_array(path, transit) == 1) {
					reset_vector(min_path); // dark magic
					for (int j = 0; j < path->len; j++) {
						push_vector(min_path, path->arr[j]);
					}
				} else {
					dfs_with_transit(next, goal, transit, path, adlist, min_path);
				}
				pop_vector(path);
			}
		}
	}
	return min_path;
}
Vector	*graph_dfs_shortest_path(AdList **adlist, int v_count, int start, int goal, int transit) {
	Vector *min_path = init_min_path(v_count);

	Vector *search_path = new_vector(2);
	push_vector(search_path, start);

	min_path = dfs_with_transit(start, goal, transit, search_path, adlist, min_path);
	
	return min_path;
}

int	main(void) {
	int N, S, T, P;
	scanf("%d %d %d %d", &N, &S, &T, &P);
	// printf("%d %d %d %d\n", N, S, T, P);

	AdList **adlist = calloc(N+1, sizeof(AdList));
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

	Vector *min_path = graph_dfs_shortest_path(adlist, N, S, T, P);

	if (min_path->len == N+1)
		printf("-1\n");
	else {
		print_vector_with_space(min_path);
	}

	return (0);
}