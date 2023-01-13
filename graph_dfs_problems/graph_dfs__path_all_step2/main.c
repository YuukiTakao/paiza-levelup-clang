#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    TYPE_INT,
    TYPE_STR,
	TYPE_VECTOR,
}	ObjectType;
typedef struct {
    union {
        char *string;
        int integer;
    } value;
} VecType;
typedef struct {
	ObjectType	type;
	VecType		*arr;
	int			len;
	int			cap;
}	Vector;
Vector	*resize_vector(Vector *self, int cap) {
	int byte = sizeof(VecType);
	int size = cap * byte;
	VecType *tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	reset_vector(Vector *vector) {
	vector->len = 0;
}
void	push_vector(Vector *self, void *elem) {
	if (self->len >= self->cap) {
		if (! resize_vector(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	if (self->type == TYPE_INT) {
		int tmp = *(int *)elem;
		self->len++;
		self->arr[self->len].value.integer = tmp;
	} else if (self->type == TYPE_STR) {
		char *tmp = *(char **)elem;
		self->len++;
		self->arr[self->len].value.string = tmp;
	} else {
		printf("error Vector type:%d\n", self->type);
        exit(1);
	}
}
void	pop_vector(Vector *self) {
	if (1 <= self->len) {
		self->len--;
	}
}
Vector	*new_vector(ObjectType type) {
	Vector *self = calloc(1, sizeof(*self));
	if (!self)
		return NULL;
	self->type = type;
	self->arr = calloc(self->cap, sizeof(VecType));
	if (!self->arr) {
		free(self);
		return NULL;
	}
	return self;
}
Vector	*new_int_vector(int cap) {
	Vector *self = new_vector(TYPE_INT);
	self->cap = cap;
	return self;
}


typedef struct {
	VecType	**arr;
	int		len;
	int		cap;
}	VVector;
VVector	*resize_vvector(VVector *self, int cap) {
	int byte = sizeof(Vector);
	int size = cap * byte;
	VecType **tmp = realloc(self->arr, size);
	if (!tmp)
		return NULL;
	self->arr = tmp;
	self->cap = cap;
	return self;
}
void	reset_vvector(VVector *vector) {
	vector->len = 0;
}
void	push_vvector(VVector *self, Vector *elem) {
	if (self->len >= self->cap) {
		if (! resize_vvector(self, self->cap * 2))
			printf("failed resize memory allocate\n");
	}
	self->len++;
	if (elem->type == TYPE_INT) {
		self->arr[self->len] = calloc(elem->len, sizeof(Vector));
		for (int i = 1; i <= elem->len; i++) {
			self->arr[self->len][i].value.integer = elem->arr[i].value.integer;
		}
	} else if (elem->type == TYPE_STR) {
		self->arr[self->len] = calloc(elem->len, sizeof(Vector));
		for (int i = 1; i <= elem->len; i++) {
			int slen = (int)strlen(elem->arr->value.string);
			for (int j = 0; j < slen; j++) {
				self->arr[self->len][i].value.string[j] = elem->arr[i].value.string[j];
			} 
		}
	}
}
void	pop_vvector(VVector *self) {
	if (1 <= self->len) {
		self->len--;
	}
}
VVector	*new_vvector(int cap) {
	VVector *self = calloc(1, sizeof(*self));
	if (!self)
		return NULL;

	self->cap = cap;
	self->arr = calloc(self->cap, sizeof(Vector));
	if (!self->arr) {
		free(self);
		return NULL;
	}
	return self;
}

int	main(void) {
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);
	// printf("%d %d %d\n", N, M, L);
	Vector *vector = new_int_vector(2);
	int a = 1234;
	push_vector(vector, &a);
	int b = 4569;
	push_vector(vector, &b);



	VVector *vv = new_vvector(2);
	push_vvector(vv, vector);

	printf("vv->len=%d\n", vv->len);
	for (int i = 1; i <= vv->len; i++) {
		printf("%d\n", vv->arr[i]
	}

	return (0);
}