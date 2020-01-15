/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** exit function builtin
*/

#include "shell.h"

void	exit_f(char **command, char **environ)
{
	(void)command;
	(void)environ;
	exit(0);
}
