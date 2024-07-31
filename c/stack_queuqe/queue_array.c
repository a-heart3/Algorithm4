#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "queue.h"

bool isEmpty(queue_array *queue)
{
	return queue->size == 0;
}

void resize(queue_array *queue, int type)
{
	/* resize
	 * every time resize, make element as 0-size-1
	 */
	int old_capacity = queue->capacity;
	if (type == 1) queue->capacity *= 2;
	else					 queue->capacity /= 2;
  char **s = (char **) calloc (queue->capacity, sizeof(char *));
	for (int i = 0; i < queue->capacity; i++) {
		s[i] = (char *) calloc (50, sizeof(char));
	}
	int i = 0;
	for (i; i < queue->size; i++) {
		strcpy(s[i], queue->str[queue->front]);
		queue->front = (queue->front + 1) % old_capacity;
	}
	queue->front = 0;
	queue->rear = i;
	queue->str = s;																						//change the str of queue;
}
		

void enqueue(queue_array *queue, char *s)
{
	strcpy(queue->str[queue->rear], s);
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->size += 1;
	if (queue->size == queue->capacity) resize(queue, 1);
}

void dequeue(queue_array *queue)
{
	assert (!isEmpty(queue));
	printf("%s, ", queue->str[queue->front]);
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	if(queue->size == queue->capacity/4) resize(queue, 0);
}

int size (queue_array *queue)
{
	return queue->size;
}
