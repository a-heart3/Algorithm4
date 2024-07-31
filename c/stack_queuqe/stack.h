#ifndef _TYPE_H_
#define _TYPE_H_
typedef struct Node {
	char s[50];
	struct NOde *next;
}Node;

typedef struct stack_link {
	int size;
	Node *first;
}stack_link;

typedef struct stack_array {
	int size;												// Record current size
	int capacity;										// Record max size
	char **data;
}stack_array;

#endif
