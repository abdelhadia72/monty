#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second top element
 *         of the stack by the top element of the stack.
 * @head: double pointer to the stack
 * @value: nnused argument (required by the opcode function pointer)
 */
void f_mod(stack_t **head, unsigned int value)
{
	stack_t *temp;
	/* fake num */
	int num = 0;
	(void)value;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n %= (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
