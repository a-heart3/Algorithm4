#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

bool isEmpty(stack_link *stack) 
{
	return (stack->first == NULL);
}	

void push(stack_link *stack, char *s)
{
	Node *new_first = (Node *) malloc (sizeof(Node));
	strcpy(new_first->s, s);
	new_first->next = stack->first;
	stack->first = new_first;
	stack->size += 1;
}

void pop(stack_link *stack)
{
	printf("%s ", stack->first->s);
	Node *old_first = stack->first;
	stack->first = stack->first->next;
	free(old_first);
	stack->size -= 1;
}

int size(stack_link *stack)
{
	return stack->size;
}
