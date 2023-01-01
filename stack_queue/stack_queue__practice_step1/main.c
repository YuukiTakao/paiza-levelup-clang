#include <stdio.h>
#include <stdlib.h>

typedef int QUEUE_TYPE;
typedef struct Queue {
	QUEUE_TYPE	*array;
	int			last_index;
	int			cap;
	int			front_idx;
}	Queue;
Queue	*new(int cap) {
	Queue *self = calloc(1, sizeof(Queue));
	if (!self)
		printf("failed Queue new...\n");
	self->cap = cap;
	self->last_index = 0;
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
int	empty(Queue *self) {
	return 0 >= (self->last_index - self->front_idx);
}
int	queue_size(Queue *self) {
	return self->last_index - self->front_idx;
}
void	pop(Queue *self) {
	if (queue_size(self) == 0) {
		printf("queue is empty...\n");
		return;
	}
	self->front_idx++;
}
QUEUE_TYPE	front(Queue *self) {
	return self->array[self->front_idx];
}
void	push_back(Queue *self, QUEUE_TYPE elem) {
	if (self->last_index >= self->cap) {
		if (resize(self, self->cap * 2) == NULL) {
			printf("failed push_back in realloc...\n");
		}
	}
	// self->array[self->last_index] = calloc(strlast_index(elem), sizeof(char));
	self->array[self->last_index] = elem;
	self->last_index++;
}

int	main(void) {
	int Q;
	scanf("%d", &Q);
	// printf("%d\n", Q);

	Queue *Q1 = new(4);
	Queue *Q2 = new(4);

	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		// printf("q=%d ", q);
		if (q == 1) {
			int k;
			scanf("%d", &k);
			// printf("k=%d ", k);

			int X;
			scanf("%d", &X);
			// printf("X=%d ", X);

			if (k == 1) {
				push_back(Q1, X);
			} else if (k == 2) {
				push_back(Q2, X);
			}

		} else if (q == 2) {
			int k;
			scanf("%d", &k);
			// printf("k=%d ", k);

			if (k == 1) {
				printf("%d\n", front(Q1));
				pop(Q1);
			} else if (k == 2) {
				printf("%d\n", front(Q2));
				pop(Q2);
			}
		} else if (q == 3) {
			printf("%d %d\n", queue_size(Q1), queue_size(Q2));
		} else {
			printf("Error!\n");
		}
		// printf("\n");
	}
	
	return (0);
}