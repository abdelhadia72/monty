#include "monty.h"

/**
 * free_stack - free all elements of the stack
 * @head: pointer to the stack
 */

void free_stack(stack_t **head)
{
    stack_t *current = *head;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
