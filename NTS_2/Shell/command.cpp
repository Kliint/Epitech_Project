#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "prompt.hpp"

static struct instruct INSTR[5] =
{
    {"display\n", &display},
    {"simulate\n", &simulate},
    {"loop\n", &loop},
    {"dump\n", &dump},
    {NULL, NULL}
};



int check_command(char *command)
{
    int i = 0;

    while (i < 5) {
        if (strcmp(command, INSTR[i].instr) == 0) {
            INSTR[i].func();
            shell();
            return (SUCCESS);
        }
        i += 1;
        if (INSTR[i].instr == NULL)
            return (FAIL);
    }
    return (SUCCESS);
}
