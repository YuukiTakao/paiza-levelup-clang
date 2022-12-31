#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int		*array;
	int		len;
	int		cap;
}	Stack;
Stack	*new(int cap) {
	Stack *self = calloc(1, sizeof(Stack));
	if (!self)
		printf("failed Stack new...\n");
	self->cap = cap;
	self->len = 0;
	self->array = calloc(self->cap, sizeof(int *));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
Stack	*resize(Stack *self, int new_cap) {
	int new_size = new_cap * sizeof(int);
		int *tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
int	pop_back(Stack *self) {
	if (self->len == 0) {
		printf("failed push_back in realloc...\n");
	}
	self->len--;
	return self->array[self->len-1];
}
int	back(Stack *self) {
	return self->array[self->len-1];
}
void	push_back(Stack *self, int elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	// printf("self->len=%d strlen=%lu elem=%s\n",self->len,strlen(elem), elem);
	// self->array[self->len] = calloc(strlen(elem), sizeof(char));
	self->array[self->len] = elem;
	self->len++;
}

int	main(void) {
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);

	Stack *stack = new(4);
	
	for (int i = 0; i < Q; i++)
	{
		int q, x;
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d", &x);
			push_back(stack, x);
		}
		if (q == 2) {
			pop_back(stack);
		}
		for (int j = 0; j < stack->len; j++) {
			printf("%d", stack->array[j]);
			if (j < stack->len - 1)
				printf(" ");
		}
		printf("\n");
	}
	

	return (0);
}