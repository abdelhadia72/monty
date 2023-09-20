#include "stack.h"
#include <string.h>

/**
 * maker - parse the ints and store them in arrays
 * @lines: array of strings containing the ints
 * @num_lines: number of ints
 * @values: array to store integer values
 * @ops: array to store operation strings
 */
void maker(char **lines, int num_lines, int values[], char **ops)
{
	char *action = NULL;
	char *value_str = NULL;
	int value = -1;
	int i = 0;

	for (i = 0; i < num_lines; i++)
	{
		action = strtok(lines[i], " ");
		if (action != NULL)
		{
			value_str = strtok(NULL, " ");
			if (value_str != NULL)
			{
				value = atoi(value_str);
			}
			else
			{
				value = 0;
			}
		}
		else
		{
			value = 0;
		}

		values[i] = value;
		*(ops++) = strdup(action);
	}
}

/**
 * execute - execute the the called function
 * @head: double pointer to the stack
 * @values: array of integer values
 * @ops: array of operation strings
 * @num_lines: number of ints
 */
void execute(stack_t **head, int values[], char **ops, int num_lines)
{
	int j = 0;
	int k = 0;

	instruction_t in[] = {
		{"push", (void (*)(stack_t **, unsigned int))push},
		{"pall", (void (*)(stack_t **, unsigned int))pall},
		{NULL, NULL},
	};

	while (j < num_lines)
	{
		while (in[k].opcode)
		{
			if (strcmp(in[k].opcode, ops[j]) == 0)
			{
				in[k].f(head, values[j]);
				break;
			}
			k++;
		}
		j++;
	}
}

/**
 * clearner - clean up dynamically allocated memory
 * @lines: array of strings containing the ints
 * @ops: array of operation strings
 * @num_lines: number of ints
 */
void clearner(char **lines, char **ops, int num_lines)
{
	int i;

	for (i = 0; i < num_lines; i++)
	{
		free(lines[i]);
		free(ops[i]);
	}
	free(lines);
}

/**
 * handler - parse the ints and store them in arrays
 * @lines: array of strings containing the ints
 * @head: pointer to the stack
 * @num_lines: number of ints
 * Return: 0 (success)
 */
int handler(stack_t **head, char **lines, int num_lines)
{
	int values[num_lines];
	char *ops[num_lines];

	maker(lines, num_lines, values, ops);
	execute(head, values, ops, num_lines);
	clearner(lines, ops, num_lines);

	return (0);
}
