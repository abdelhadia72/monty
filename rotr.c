#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @head: Double pointer to the stack
 * @value: un used
 */
void rotr(stack_t **head, unsigned int value)
{
	stack_t *last = *head;
	stack_t *secondLast = last;
	stack_t *temp = last;
	(void)value;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	while (temp->next != NULL)
	{
		secondLast = temp;
		temp = temp->next;
	}

	secondLast->next = NULL;
	temp->next = last;
	last->prev = temp;
	*head = temp;
	temp->prev = NULL;
}
