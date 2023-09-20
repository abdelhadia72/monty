#include "monty.h"

/**
 * push - push a new node to the stack
 * @stack: pointer to the stack
 * @value: value to be added to the stack
 *
 */

void push(stack_t **head, unsigned int value)
{
    stack_t *newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        // Handle memory allocation error
        fprintf(stderr, "Error: can't malloc\n");
        exit(EXIT_FAILURE);
    }
    newNode->n = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}
