#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int STACK_TYPE;
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
		// self->array[self->len] = calloc(strlen(elem), sizeof(STACK_TYPE));
	self->array[self->len] = elem;
	self->len++;
}

void	stack_print(Stack *stack) {
	int size = stack->len;
	for (int i = size - 1; i >= 0; i--) {
		printf("%d\n", stack->array[i]);
	}
}

int	main(void) {
	int N;
	scanf("%d", &N);
	// printf("%d\n", N);

	Stack *st1 = new(4);
	Stack *st2 = new(4);
	Stack *st3 = new(4);

	for (int i = 0; i < N; i++) {
		char *q = calloc(5, sizeof(char));
		scanf("%s", q);
		
		if (strcmp(q, "push") == 0) {
			int num;
			scanf("%d", &num);
			

			int X;
			scanf("%d", &X);

			if (num == 1) {
				push_back(st1, X);
			} else if (num == 2) {
				push_back(st2, X);
			} else if (num == 3) {
				push_back(st3, X);
			}
		} else if (strcmp(q, "pop") == 0) {
			int num;
			scanf("%d", &num);
			
			if (num == 1) {
				pop_back(st1);
			} else if (num == 2) {
				pop_back(st2);
			} else if (num == 3) {
				pop_back(st3);
			}
		}
	}

	stack_print(st1);
	stack_print(st2);
	stack_print(st3);
	
	return (0);
}