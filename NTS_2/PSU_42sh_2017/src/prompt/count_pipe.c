/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** count_pipe
*/

#include <stdlib.h>
#include "shell2.h"

int	count_pipe(char *command)
{
	int	i = 0;
	int	pipe_count = 0;
		
	while (command[i]) {
		if (command[i] == '|')
			pipe_count += 1;
		i += 1;
	}
	return (pipe_count);
}

int	check_shell2(char c)
{
	if (c == ';' ||
	    c == '|' ||
	    c == '>')
		return (0);
	return (-1);
}

int	count_shell2(char *str)
{
	int	i = 0;
	int	acc = 0;

	while (str[i]) {
		if (check_shell2(str[i]) == 0)
			acc += 1;
		i += 1;
	}
	return (acc);
}

char	*malloc_shell2(char *str)
{
	int	ct_shell2 = count_shell2(str);
	char	*counted_shell2;

	if (ct_shell2 == 0)
		return (NULL);
	counted_shell2 = malloc(sizeof(char) * ct_shell2 + 1);
	if (counted_shell2 == NULL)
		return (NULL);
	return (counted_shell2);
}

char	*command_shell2(char *str)
{
	int	i = 0;
	char	*command;
	int	y = 0;

	if (str == NULL)
		return (NULL);
	command = malloc_shell2(str);
	while (str[i]) {
		if (check_shell2(str[i]) == 0) {
			command[y] = str[i];
			y += 1;
		}
		i += 1;
	}
	command[y] = '\0';
	return (command);
}
