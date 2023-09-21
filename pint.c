#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @head: pointer to the stack
 * @value: unused
 *
 * Return: void
 */
void pint(stack_t **head, unsigned int value)
{
	stack_t *current = *head;
	(void)value;

	if (current)
	{
		printf("%d\n", current->n);
	}
	else
	{
		fprintf(stderr, "Error: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
}
