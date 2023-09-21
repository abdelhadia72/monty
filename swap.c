#include "monty.h"

/**
 * swap - swap 2ed with top of the stack
 * @head: pointer to the stack
 * @value: unused
 *
 * Return: void
 */
void swap(stack_t **head, unsigned int value)
{
	int holder = 0;
	stack_t *current = (*head);
	(void)value;

	holder = current->next->n;
	current->next->n = current->n;
	current->n = holder;
}
