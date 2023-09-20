#include "stack.h"

/**
 * push - push a new note tot the stack
 * @stack: pointer to the stack
 * @value: value to be added to the stack
 *
 * Return: 0 (success), -1 (failure)
 */

int push(stack_t **stack, unsigned int value)
{
	if (!value)
		return (-1);

	stack_t *newNode = malloc(sizeof(stack_t));

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
