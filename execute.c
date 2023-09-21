#include "monty.h"

/**
 * execute - execute Monty bytecode instructions
 * @head: double pointer to the stack
 * @line: a line of Monty bytecode
 * @len: line number in the Monty bytecode file
 *
 * Return: 0 on success, -1 on error
 */
int execute(stack_t **head, char *line, unsigned int len)
{

	instruction_t funs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", f_div},
		{"mul", f_mul},
		{NULL, NULL},
	};

	unsigned int value;
	unsigned int i = 0;
	char *token_z = NULL;

	(void)len;

	token_z = strtok(line, "\n\t ");
	while (token_z != NULL)
	{
		for (i = 0; funs[i].opcode != NULL; i++)
		{
			if (strcmp(token_z, funs[i].opcode) == 0)
			{
				token_z = strtok(NULL, "\n\t ");
				if (!token_z)
					token_z = "0";

				value = atoi(token_z);

				funs[i].f(head, value);

				break;
			}
		}
		token_z = strtok(NULL, "\n\t ");
	}

	return (0);
}
