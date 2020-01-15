/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** execution of command
*/

#include "shell.h"

int	exec_command(char *command_p, char **command, char **environ)
{
	pid_t	pid = fork();
	int	statuts;

	if (pid == -1) {
		my_printf("[Error]: Fork syscall problem \n");
		exit(84);
	}
	if (pid == 0)
		statuts = execution_simple_command(command_p, command, environ);
	else {
		waitpid(0, &statuts, 0);
		statuts = catch_sgve(statuts);
	}
	return (statuts);
}

int	execution_simple_command(char *command_p, char **command,char **environ)
{
	int status = execve(command_p, command, environ);

	if (status == -1) {
		putstr(command_p);
		putstr(": Command not found.\n");
		prompt(environ);
	}
	return (status);
}
