#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @head: Double pointer to the stack
 * @value: unused
 *
 * Return: void
 */
void add(stack_t **head, unsigned int value)
{
	(void)value;

	(*head)->next->n += (*head)->n;

	stack_t *temp = *head;
	*head = (*head)->next;
	free(temp);
}
