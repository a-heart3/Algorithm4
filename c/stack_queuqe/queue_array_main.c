#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

/* because we are operate on the link,
 * so don't need return value
 */
bool isEmpty(queue_array *queue);
void enqueue (queue_array *queue, char *s);
void dequeue(queue_array *queue);
int size(queue_array *queue);
void initial(queue_array *queue)
{
	/* Use to initialize the stack */
	queue->size = 0;
	queue->capacity = 1;
	queue->front = 0;
	queue->rear = 0;
	queue->str = (char **) malloc (sizeof(char *));
	queue->str[0] = (char *) calloc (50, sizeof(char));
}
void Delete_n (char *s, int length) {
	/* Delete the \n in the end of line */
	s[length-1] = '\0';
}

int main(int argc, char *argv[]) {
	assert (argc > 1);
	char line[1000];																											// read line
	char *token;
	FILE *fdin;
	int count = 0;
	queue_array *queue = (queue_array *) malloc (sizeof(queue_array));				// create a stack_link
	initial(queue);																												// initialize
	fdin = fopen(argv[1], "r");
	while (fgets(line, 1000, fdin) != NULL) {															// file is not end
		Delete_n(line, strlen(line));																				// tackle the \n in the line end
		token = strtok(line, " ");																					// split the first argumrnt
		while(token != NULL) {																							// push all the argument
			enqueue(queue, token);
			token = strtok(NULL, " ");
		}	
		count = size(queue);																								// get stack size
		for(int i = 0; i < count; i++) {																		// pop, reverse the string
			dequeue(queue);
		}		
		printf("\n");
	}
	printf("queue_array is OK\n");	
	return 0;
}
	
