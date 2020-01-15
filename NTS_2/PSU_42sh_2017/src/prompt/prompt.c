/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** prompt display
*/

#include "shell.h"

void	prompt_display(char **environ)
{
	int	end = 43;
	int	status;
	
	while (end) {
		if ((status = prompt(environ)) == -1) {
			end = !end;
			exit(status);
		}
	}
}

int	prompt(char **environ)
{
	char	*command_get;
	char	**command;
	static int	status = 0;

	signal(SIGINT, get_sig);
	my_printf("$>:");
	command_get = get_next_line(0);
	if (command_get == NULL) {
		my_printf("exit\n");
		exit (status);
	}
	if (command_get[0] == '\n')
		prompt(environ);
	else {
		if ((command = my_str_to_wordtab(command_get)) == NULL)
			return (-1);
		if ((status = command_interpreter(environ, command[0], command)) == -1)
			prompt(environ);
		free(command);
	}
	if (status != 0) {
                return (status);
        }
	return (status);
}
