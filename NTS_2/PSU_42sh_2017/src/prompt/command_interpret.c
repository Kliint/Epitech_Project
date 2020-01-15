/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** cmmand_interpret
*/

#include "shell.h"

static	struct types_c BSC[] =
{
//	{"cd", &cd},
//	{"env", &disp_tab},
	{"echo", &echo},
	{"exit\n", &exit_f},
//	{"setenv", &my_setenv},
//	{"unsetenv", &unsetenv},
	{NULL, 0}
};

int	command_interpreter(char **environ, char *command_get, char **command)
{
	char	*instr;
	int	status;
	
	if ((basic_command(command, environ)) != 0) {
		if ((instr = check_function((my_access(environ, command_get)),
					    command_get)) == NULL) {
			my_printf("%s: Command not found.\n", command_get);
			prompt(environ);
		}
		if ((status = exec_command(instr, command, environ)) == 0)
			prompt(environ);
	}
	return (status);
}

int	basic_command(char **command, char **environ)
{
	int	i = 0;
	
	while (BSC[i].flag != NULL) {
		if (my_strncmp(command[0], BSC[i].flag, my_strlen(command[0])) == 0) {
			BSC[i].func(command, environ);
				return (0);
		}
		i += 1;
	}
	return (-1);
}

