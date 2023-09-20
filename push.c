#include "monty.h"

/**
 * push - push a new node to the stack
 * @head: pointer to the stack
 * @value: value to be added to the stack
 *
 */
void push(stack_t **head, unsigned int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
		exit(EXIT_FAILURE);

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head)
	{
		(*head)->prev = newNode;
	}
}
