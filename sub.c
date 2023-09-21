#include "monty.h"

/**
 * sub - Subtract the top element of the stack from the second top element
 * @head: Double pointer to the stack
 * @value: Unused argument (required by the opcode function pointer)
 */
void sub(stack_t **head, unsigned int value)
{
	stack_t *temp;

	(void)value;

	/* fake line fake it late ?*/
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", 0);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n -= (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
