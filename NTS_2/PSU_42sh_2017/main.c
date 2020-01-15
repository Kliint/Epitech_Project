/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** main
*/

#include "shell.h"

int	main(int argc, char *argv[argc], char **env)
{
	(void)argc;
	(void)argv;
	if (env == NULL)
		return (EXIT_FAILURE);
	prompt_display(env);
	return (EXIT_SUCCESS);
}
