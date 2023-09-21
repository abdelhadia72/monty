#include "monty.h"

/**
 * pchar - Print the character at the top of the stack.
 * @head: Double pointer to the stack
 * @value: Unused argument (required by the opcode function pointer)
 */
void pchar(stack_t **head, unsigned int value)
{
	int num = 0;
	(void)value;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		exit(EXIT_FAILURE);
	}

	putchar((*head)->n);
	putchar('\n');
}
