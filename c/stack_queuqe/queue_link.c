#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

bool isEmpty(queue_link *queue)
{
	return (queue->first == NULL);
}

void enqueue(queue_link *queue, char *s) 
{
	Node *oldrear = queue->rear;
	queue->rear = (Node *) malloc (sizeof(Node));
	strcpy(queue->rear->data, s);
	queue->size += 1;
	if(isEmpty(queue)) queue->first = queue->rear;
	else							 oldrear->next = queue->rear;
}	

void dequeue(queue_link *queue, char s[])
{
	assert(!isEmpty(queue));
	printf("%s, ", queue->first->data);
	queue->first = queue->first->next;
	queue->size -= 1;
	if(isEmpty(queue)) queue->rear = NULL;
}

int size(queue_link *queue)
{
	return queue->size;
}	
	
