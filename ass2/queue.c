#include <stdlib.h>
#include <stdio.h>

typedef struct Queue
{
    int* a;
    int size;
    int max_size;
    int front;
    int tail;
} Queue;

void init(Queue* q, int size)
{
    q->size = size;
    q->a = malloc(sizeof(Queue) * size);
    q->max_size = size;
}
