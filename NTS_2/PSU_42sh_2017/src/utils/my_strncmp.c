/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** strncmp
*/

#include "shell.h"

int	my_strncmp(char *str, char *str2, int len)
{
	int	i = 0;

	while (i < len && str[i] && str2[i]) {
		if (str[i] != str2[i])
			return (-1);
		i += 1;
	}
	return (0);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i = 0;
	
	while (s1[i] && s2[i]) {
		if (s1[i] != s2[i])
			return (-1);
		i += 1;
	}
	return (0);
}
