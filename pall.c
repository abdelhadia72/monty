#include "monty.h"

/**
 * pall - print all elements of the stack
 * @stack: pointer to the stack
 * @value: unused
 *
 * Return: void
 */
void pall(stack_t **head, unsigned int value)
{
    stack_t *current = *head;
    (void)value;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}