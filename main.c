#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;
    char line[256];

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

    while (fgets(line, sizeof(line), file) != NULL)
    {
        execute(line);
    }

    fclose(file);

    return 0;
}
