/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** access_check
*/

#include "shell.h"

char    *check_function(char **new, char *command_get)
{
	int   i = 0;
	char  *initstr;

	while (new[i] != NULL) {
		initstr = strcat(new[i], clean_command((command_get)));
		if ((access(initstr, F_OK || W_OK)) == 0)
			return (initstr);
		else
			i++;
	}
	return (NULL);
}

char    *check_path(char **new)
{
	int   i = 0;

	while (new[i] != NULL) {
		if ((access(new[i], F_OK || W_OK)) == 0)
			return (new[i]);
		else
			i++;
	}
	return (NULL);
}

char    **my_access(char **env, char *command)
{
	char  **path;
	char  *str;
	int   x = 0;
	int   y = 0;
	int   i = 0;

	if (command[0] == '.' && command[1] == '/') {
		str = clean_str(my_env(env, "PWD"));
		str = strcat(str, "/");
		path = malloc(sizeof(char) * 255);
		path[0] = malloc(sizeof(char *) * 255);
		path[0] = strcpy(path[0], str);
		path[1] = NULL;
		return (path);
	}
	str = env_shell(env);
	path = malloc(sizeof(char) * 255);
	path[0] = malloc(sizeof(char *) * 255);
	while (str[i] != '=')
		i++;
	i = i + 1;
	while (str[i] != '\0') {
		if (str[i] == ':') {
			path[x++][y] = '/';
			i++;
			path[x] = malloc(sizeof(char *) * 255);
			y = 0;
		}
		path[x][y++] = str[i++];
	}
	path[x][y] = '/';
	path[++x] = NULL;
	return (path);
}
