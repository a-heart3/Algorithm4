#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

/* because we are operate on the link,
 * so don't need return value
 */
bool isEmpty(stack_array *stack);
void push (stack_array *stack, char *s);
void pop(stack_array *stack);
int size(stack_array *stack);
void initial(stack_array *stack)
{
	/* Use to initialize the stack */
	stack->size = 0;
	stack->capacity = 1;
	stack->data = (char **) malloc (sizeof(char *));
	stack->data[0] = (char *) calloc (50, sizeof(char));
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
	stack_array *stack = (stack_array *) malloc (sizeof(stack_array));				// create a stack_link
	initial(stack);																												// initialize
	fdin = fopen(argv[1], "r");
	while (fgets(line, 1000, fdin) != NULL) {															// file is not end
		Delete_n(line, strlen(line));																				// tackle the \n in the line end
		token = strtok(line, " ");																					// split the first argumrnt
		while(token != NULL) {																							// push all the argument
			push(stack, token);
			token = strtok(NULL, " ");
		}	
		count = size(stack);																								// get stack size
		for(int i = 0; i < count; i++) {																		// pop, reverse the string
			pop(stack);
		}		
		printf("\n");
	}
	printf("stack array is OK\n");
	
	return 0;
}
	
