#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QUEUE_TYPE;
typedef struct Queue {
	QUEUE_TYPE	*array;
	int			len;
	int			cap;
	int			front_idx;
}	Queue;
Queue	*new(int cap) {
	Queue *self = calloc(1, sizeof(Queue));
	if (!self)
		printf("failed Queue new...\n");
	self->cap = cap;
	self->len = 0;
	self->front_idx = 0; 
	self->array = calloc(self->cap, sizeof(QUEUE_TYPE));
	if (self->array == NULL) {
		printf("failed array memory allocate...\n");
		free(self);
		return NULL;
	}
	return self;
}
Queue	*resize(Queue *self, int new_cap) {
	int new_size = new_cap * sizeof(QUEUE_TYPE);
	QUEUE_TYPE *tmp = realloc(self->array, new_size);
		if (tmp == NULL) {
		printf("failed array realloc...\n");
		return NULL;
	}
	self->array = tmp;
	self->cap = new_cap;
	return self;
}
void	pop(Queue *self) {
	self->front_idx++;
}
QUEUE_TYPE	front(Queue *self) {
	return self->array[self->front_idx];
}
void	push_back(Queue *self, QUEUE_TYPE elem) {
	if (self->len >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	// self->array[self->len] = calloc(strlen(elem), sizeof(char));
	self->array[self->len] = elem;
	self->len++;
}

int	main(void) {
	int N;
	scanf("%d", &N);
	// printf("%d\n", N);

	Queue *queue = new(4);

	for (int i = 0; i < N; i++)
	{
		int q;
		scanf("%d", &q);
		if (q == 1) {
			int X;
			scanf("%d", &X);
			push_back(queue, X);
			for (int i = queue->front_idx; i < queue->len; i++) {
				if (queue->front_idx < i)
					printf(" ");
				printf("%d", queue->array[i]);
			}
			printf("\n");
		} else if (q == 2) {
			// printf("%d\n", front(queue));
			pop(queue);
			for (int i = queue->front_idx; i < queue->len; i++) {
				if (queue->front_idx < i)
					printf(" ");
				printf("%d", queue->array[i]);
			}
			printf("\n");
		}
	}
	
	return (0);
}