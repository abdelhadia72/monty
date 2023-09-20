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
	(void)value;
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	return (0);
}
