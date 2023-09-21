#include "monty.h"

/**
 * f_mul - Multiply the second top element of the stack with the top element
 * @head: Double pointer to the stack
 * @value: Unused argument (required by the opcode function pointer)
 */
void f_mul(stack_t **head, unsigned int value)
{
	stack_t *temp;
	(void)value;

	(*head)->next->n *= (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
