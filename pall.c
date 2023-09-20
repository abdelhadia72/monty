#include "stack.h"

/**
 * pall - print all elements of the stack
 * @stack: pointer to the stack
 * @value: unused
 *
 * Return: 0 (success)
 */
int pall(stack_t **stack, unsigned int value)
{
	stack_t *current = *stack;
	(void)value;

	while (current)
	{
		stack_t *temp = current;
		printf("%d\n", temp->n);
		current = current->next;
	}

	return (0);
}
