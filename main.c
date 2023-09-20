#include "stack.h"

/**
 * main - main function entry point
 * @argc: number of arguments
 * @argv: 2d array of arguments
 *
 * Return: 0 (success), 1 (failure)
 */
int main(int argc, char **argv)
{
	int file;
	char *line = NULL;
	stack_t *head = NULL;
	char **lines = NULL;
	size_t len = 0;
	int num_lines = 0;

	if (argc != 2)
	{
		printf("Eroor");
		return (1);
	}

	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		perror("Error");
		return (1);
	}

	while (getline(&line, &len, fp) != -1)
	{
		char **temp = malloc((num_lines + 1) * sizeof(char *));

		if (temp == NULL)
		{
			perror("Error");
			return (1);
		}
		memcpy(temp, lines, num_lines * sizeof(char *));
		free(lines);
		lines = temp;
		lines[num_lines] = strdup(line);
		num_lines++;
	}
	free(line);
	fclose(fp);
	handler(&head, lines, num_lines);
	return (0);
}
