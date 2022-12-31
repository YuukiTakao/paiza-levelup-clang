#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * STACK_TYPE;
typedef struct Stack {
	STACK_TYPE	*array;
	int			len;
	int			cap;
}	Stack;
Stack	*new(int cap) {
	Stack *self = calloc(1, sizeof(Stack));
	if (!self)
		printf("failed Stack new...\n");
	self->cap = cap;
	self->len = 0;
	self->array = calloc(self->cap, sizeof(STACK_TYPE));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
Stack	*resize(Stack *self, int new_cap) {
	int new_size = new_cap * sizeof(STACK_TYPE);
	STACK_TYPE *tmp = realloc(self->array, new_size);
	if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
STACK_TYPE	pop_back(Stack *self) {
	if (self->len == 0) {
		printf("failed push_back in realloc...\n");
	}
	self->len--;
	return self->array[self->len];
}
STACK_TYPE	back(Stack *self) {
	return self->array[self->len-1];
}
void	push_back(Stack *self, STACK_TYPE elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	if (sizeof(STACK_TYPE) == 1) {
		self->array[self->len] = calloc(strlen(elem), sizeof(STACK_TYPE));
	}
	self->array[self->len] = elem;
	self->len++;
}

void	stack_print(Stack *stack) {
	int size = stack->len;
	for (int i = 0; i < size; i++) {
		if (i >= 1)
			printf(" ");
		printf("%s", stack->array[i]);
	}
	printf("\n");
}

int	main(void) {
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);

	Stack *stack = new(4);

	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		if (q == 1) {
			char *X = calloc(2, sizeof(char));
			scanf("%s", X);
			push_back(stack, X);

			// stack_print
			stack_print(stack);
		} else if (q == 2) {
			// stack_print
			printf("%s\n", pop_back(stack)); 
			stack_print(stack);
		}
	}

	

	return (0);
}