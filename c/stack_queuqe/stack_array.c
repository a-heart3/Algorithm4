#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

bool isEmpty(stack_array *stack) 
{
	return !(stack->size == 0);
}

void resize(stack_array *stack, int type)
{
	/* resize the stack
	 * If type is 1, represent expand
	 * If type is 0, represent shrink
	 */
	char **new_array;
	int new_capacity;
	if (type == 1) new_capacity = 2 * stack->capacity;
	else					 new_capacity = stack->capacity / 2; 
	new_array = (char **) calloc (new_capacity, sizeof(char *));
	for (int i = 0; i < new_capacity; i++) {
		new_array[i] = (char *) calloc (50, sizeof(char));
	}	
	for (int i = 0; i < stack->size; i++) {
		strcpy(new_array[i], stack->data[i]);
	}
	stack->data = new_array;
	stack->capacity = new_capacity;
}

void push(stack_array *stack, char *s)
{
	/* First push, top++
	 * then judge whether reach the capacity
	 */
	strcpy(stack->data[stack->size], s);
	stack->size += 1;
	if (stack->size == stack->capacity) {
		resize (stack, 1);
	}
}

void pop(stack_array *stack) 
{
	/* First judge whether the stack is empty
	 * pop
	 * whether shrink
	 */
	assert(isEmpty(stack));
	stack->size -= 1;
	printf("%s ", stack->data[stack->size]);
	if (stack->size <= stack->capacity/4) {
		resize (stack, 0);
	}
}
	
int size(stack_array *stack)
{
	return stack->size;
}
