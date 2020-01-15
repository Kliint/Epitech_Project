/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** env_fucntion
*/

#include "shell.h"

int     path_size(char *str)
{
	int   i = 0;
	int   acc = 0;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0') {
		while (str[acc] != '=')
			acc ++;
		i++;
	}
	return (i - acc);
}

char    *my_env(char **environ, char *path)
{
	int   y = 0;

	while (environ[y] != NULL) {
		if (my_strncmp(environ[y], path, 3) == 0)
			return (environ[y]);
		y++;
	}
	return (NULL);
}

char    **my_path(char *str)
{
	char  **str_c;

	str_c = NULL;
	str_c = my_str_to_wordtab(str);
	return (str_c);
}
