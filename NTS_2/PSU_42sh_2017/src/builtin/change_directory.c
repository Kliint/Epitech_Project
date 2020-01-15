/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** Change directory 
*/

#include "my.h"
#include "shell.h"

void	cd(char **command, char **environ)
{
	char	*path = clean_str(my_env(environ, "HOME"));
	char	*old_path = clean_str(my_env(environ, "PWD"));
	int	err;

	err = change_directory(command[0], path, old_path);
	if (err == 84)
		return ;
	return ;
}

char	*add_path(char *bk_pwd, char *dest)
{
	int	size = my_strlen(bk_pwd);
	char	*npwd = malloc(sizeof(char) * size);
	int	i;
	char	*dots="/";

	if (npwd == NULL)
		return (NULL);
	if (dest[0] != '/' &&
	    (my_strcmp(dest, "..") != 0)) {
		npwd = my_strcpy(npwd, bk_pwd);
		npwd[size] = '\0';
		if ((my_strcmp(npwd, "/")) != 0)
			npwd = my_strcat(npwd, "/");
		npwd = my_strcat(npwd, dest);
		return (npwd);
	    }
	if ((my_strcmp(dest, "..") == 0)) {
		i = size;
		while (bk_pwd[i] != '/' && i != 0)
			i -= 1;
		if (i != 0)
			return (dots);
		return (npwd);
	}
	return (dest);
}

void	change_directory(char *dest, char **env)
{
	char	*old_pwd = clean_str((my_env(env, "PWD")));
	char	*usr = clean_str((my_env(env,"HOME")));
	char	*bk_pwd = clean_str((my_env(env, "OLDPWD")));

	if (dest == NULL || (my_strcmp(dest, "--") == 0)) {
		setenv("OLDPWD", bk_pwd, 1);
		setenv("PWD", usr, 1);
		chdir(usr);
	}
	else if ((my_strcmp(dest, "-")) == 0) {
		chdir(old_pwd);
		setenv()
	}
		
		
}
