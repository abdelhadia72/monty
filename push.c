#include "stack.h"

int push(stack_t **stack, unsigned int value)
{
	stack_t *newNode;

	if (!value)
		return (-1);

	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		printf("can't malloc");
		return (-1);
	}

	newNode->n = value;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (!*stack)
	{
		*stack = newNode;
	}
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
	return (0);
}