#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "prompt.hpp"

int shell(void)
{
    int status = CONTINUE;
    char *command; 
    const int read = 0;

    write(1, ">", 1);
    signal(SIGINT, intHandler);
    while (status != EXIT_FAILURE || status != EXIT_SUCCESS) {
        command = get_next_line(read);
        if (command == NULL) {
            shell();
        }
        if (*command == '\n') {
            shell();
        }
        if (check_command(command) == FAIL)
            status = EXIT_FAILURE;

        if (strcmp(command, "exit\0") == 0)
            status = EXIT_SUCCESS;
        }
    return (status);
}

void intHandler(int sig)
{
    if (sig == 2)
        exit(0);
}

int main()
{
    shell();
    return (0);
}