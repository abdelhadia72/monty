#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;
    char *line;
    size_t len;
    ssize_t read;

    if (argc < 2)
    {
        printf("USAGE: monty file\n");
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    line = NULL;
    len = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        execute(line);
    }

    free(line);
    fclose(file);

    return 0;
}