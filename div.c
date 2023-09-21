#include "monty.h"

/**
 * f_div - Divide the second top element of the stack by the top element
 * @head: Double pointer to the stack
 * @value: Unused argument (required by the opcode function pointer)
 */
void f_div(stack_t **head, unsigned int value)
{
	stack_t *temp;
	(void)value;

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", 0);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
