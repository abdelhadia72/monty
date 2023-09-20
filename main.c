#include "monty.h"

/**
 * main - entry point for Monty interpreter
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{

	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = _getline(&line, &len, file)) != -1)
	{
		char *line_copy = strdup(line);
		if (line_copy == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}

		/*printf("%s\n", line_copy);*/
		execute(line_copy);

		free(line_copy);
	}

	fclose(file);
	free(line);

	return (0);
}
