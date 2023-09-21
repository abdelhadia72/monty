#include "monty.h"

/**
 * pop - remoe top of the stack
 * @head: pointer to the stack
 * @value: unused
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int value)
{
    (void)value;

    stack_t *tmp = *head;
    if (*head)
    {
        *head = (*head)->next;
        free(tmp);
    }
    else
    {
        fprintf(stderr, "Error: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
}