#include "monty.h"

/**
 * execute - execute Monty bytecode instructions
 * @line: a line of Monty bytecode
 *
 * Return: 0 on success
 */
stack_t *head = NULL;

int execute(char *line)
{
	/* printf("our is %s\n", line); */
	instruction_t funs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
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
				/* printf("run %s\n", token_z); */

				token_z = strtok(NULL, "\n\t ");
				if (!token_z)
					token_z = "0";

				value = atoi(token_z);
				/* printf("run %i\n", value); */
				/* printf("run %i\n", value); */
				funs[i].f(&head, value);
				break;
			}
		}
		token_z = strtok(NULL, "\n\t ");
	}

	return (0);
}
