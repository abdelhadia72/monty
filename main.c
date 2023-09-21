#include "monty.h"

int process_file(const char *filename);

/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char **argv)
{
	const char *filename;
	int result;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	result = process_file(filename);

	return (result);
}

/**
 * process_file - Process a Monty bytecode file.
 * @filename: The name of the Monty bytecode file to process.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int process_file(const char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *line_copy;
	int result;
	unsigned int lens = 0;
	stack_t *head = NULL;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while ((read = _getline(&line, &len, file)) != -1)
	{
		lens++;
		line_copy = _strdup(line);
		if (line_copy == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			free_stack(&head);
			fclose(file);
			free(line);
			return (EXIT_FAILURE);
		}

		result = execute(&head, line_copy, lens);

		if (result == -1)
		{
			fprintf(stderr, "L%d: Unknown instruction %s", lens, line_copy);
			free(line_copy);
			free_stack(&head);
			fclose(file);
			free(line);
			return (EXIT_FAILURE);
		}

		free(line_copy);
	}

	free_stack(&head);
	fclose(file);
	free(line);

	return (EXIT_SUCCESS);
}
