#include "monty.h"

int execute(char *line)
{
    char *token_z = NULL;
    token_z = strtok(line, "\n\t ");
    int i = 0;
    int value;

    stack_t *head = NULL;

    instruction_t funs[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL},
    };

    while (token_z != NULL)
    {
        for (i = 0; funs[i].opcode != NULL; i++)
        {
            if (strcmp(token_z, funs[i].opcode) == 0)
            {
                token_z = strtok(NULL, "\n\t ");
                if (!token_z)
                    token_z = "90";

                value = atoi(token_z);
                funs[i].f(&head, value);
                // printf("The value is %i\n", value);
                break;
            }
        }
        token_z = strtok(NULL, "\n\t ");
    }

    return 0;
}
