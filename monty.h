#ifndef MONTY_H
#define MONTY_H

/* libs */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* functions */
int _getline(char **lineptr, size_t *n, FILE *stream);
char *_strdup(char *str);
int execute(char *line);
void free_stack(stack_t **head);
void push(stack_t **head, unsigned int value);
void pall(stack_t **head, unsigned int value);
void pint(stack_t **head, unsigned int value);
void pop(stack_t **head, unsigned int value);
void swap(stack_t **head, unsigned int value);
void add(stack_t **head, unsigned int value);
void nop(stack_t **head, unsigned int value);

#endif
