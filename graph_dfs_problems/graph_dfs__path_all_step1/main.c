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
void	reset_vector(Vector *vector) {
	vector->len = 0;
}
void	push_vector(Vector *self, int elem) {
	if (self->len >= self->cap) {
		if (! resize_vector(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->arr[++self->len] = elem;
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

int	main(void) {
	int N, S;
	scanf("%d %d", &N, &S);
	// printf("%d %d\n", N, S);

	Vector **vec = calloc(N+1, sizeof(Vector));
	int v, a;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v);

		if (vec[i] == NULL) {
			vec[i] = new_vector(4);
		}
		for (int j = 1; j <= v; j++) {
			scanf("%d", &a);
			push_vector(vec[i], a);
		}
	}

	qsort(vec[S]->arr, vec[S]->len, sizeof(int), cmp_asc);

	for (int i = 1; i <= N; i++) {
		if (i == S) {
			for (int j = 1; j <= vec[i]->len; j++) {
				if (j >= 2)
					printf(" ");
				printf("%d", vec[i]->arr[j]);
			}
			printf("\n");
		}
	}

	return (0);
}