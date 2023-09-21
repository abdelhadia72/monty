#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @head: Double pointer to the stack
 * @value: Unused argument (required by the opcode function pointer)
 */
void rotl(stack_t **head, unsigned int value)
{
	stack_t *first = *head;
	stack_t *second = first->next;
	stack_t *temp = first;
	(void)value;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	*head = second;
	second->prev = NULL;
	temp->next = first;
	first->prev = temp;
	first->next = NULL;
}
