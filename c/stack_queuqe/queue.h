#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef struct Node {
	char data[50];
	struct Node *next;
}Node;

typedef struct queue_link {
	int size;
	Node *first;										// first is reference the first node in the queue
	Node *rear;
}queue_link;

typedef struct queue_array {
	int size;
	int capacity;
	int front;
	int rear;
	char **str;
}queue_array;

#endif
