#include "stack.h"
#include <stdio.h>
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

/**
 * main - main function entry point
 * @argc: number of arguments
 * @argv: 2d array of arguments
 *
 * Return: 0 (success), 1 (failure)
 */
int main(int argc, char **argv)
{
	/* int file; */
	char line[1024];
	stack_t *head = NULL;
	char **lines = NULL;
	int num_lines = 0;
	FILE *fp;
	char **temp;

	if (argc != 2)
	{
		printf("Eroor");
		return (1);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		perror("Error");
		return (1);
	}

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		temp = malloc((num_lines + 1) * sizeof(char *));

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
	fclose(fp);
	handler(&head, lines, num_lines);
	return (0);
}
