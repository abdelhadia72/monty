#include "monty.h"

/**
 * execute - execute Monty bytecode instructions
 * @line: a line of Monty bytecode
 *
 * Return: 0 on success
 */

int execute(char *line)
{
	stack_t *head = NULL;

	instruction_t funs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	unsigned int value;
	unsigned int i = 0;
	char *token_z = NULL;

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
				funs[i].f(&head, value);
				break;
			}
		}
		token_z = strtok(NULL, "\n\t ");
	}

	return (0);
}
