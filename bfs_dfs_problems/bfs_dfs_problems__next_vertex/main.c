#include <stdio.h>
#include <stdlib.h>

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
}	ad_list_t;
ad_list_t *arr_resize(ad_list_t *self, int cap) {
	int byte = sizeof(int);
	int size = cap * byte;
	int *tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	push_back(ad_list_t *self, int elem) {
	if (self->len >= self->cap) {
		if (! arr_resize(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->arr[self->len] = elem;
	self->len++;
}
ad_list_t *array_new(int cap) {
	ad_list_t *self = calloc(1, sizeof(*self));
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

	ad_list_t **ad_list = calloc(N+1, sizeof(ad_list_t));

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		// printf("%d %d\n", a, b);
		if (ad_list[a] == NULL) {
			ad_list[a] = array_new(1);
		}
		if (ad_list[b] == NULL) {
			ad_list[b] = array_new(1);
		}
		push_back(ad_list[a], b);
		push_back(ad_list[b], a);
	}

	qsort(ad_list[X]->arr, ad_list[X]->len, sizeof(int), int_compare);

	for (int i = 0; i < ad_list[X]->len; i++) {
		printf("%d\n", ad_list[X]->arr[i]);
	}
	return (0);
}